#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

constexpr int MX_N=2000, INF=1000000000;
int N,M,S,T;
int p[MX_N];
vector<ii> matches;
bool vis[MX_N];
int f;

map<int,int> res[MX_N];

void augment(int u, int minE){
    if(u==S){
        f = minE;
        return;
    }
    if(p[u] != -1){
        augment(p[u], min(minE,res[p[u]][u]));
        res[p[u]][u]-=f;
        res[u][p[u]]+=f;
    }
}

int main(){
    while(1){
        scanf("%d",&N);
        if(N==-1)
            break;
        scanf("%d",&M);
        for(int i = 1; i <= N; ++i)
            scanf("%d",&p[i]);
        for(int i =0; i < MX_N; ++i)
            res[i].clear();
        matches.clear();
        int a,b;
        int mcnt=0;
        for(int i = 0; i < M; ++i){
            scanf("%d %d",&a,&b);
            if(a==N || b==N)
                p[N]+=2;
            else
                mcnt+=2;
            matches.push_back({a,b});
        }
        S = 0;
        T = M + N + 5;
        bool fail = false;
        for(int i = 1; i < N && !fail; ++i){
            res[i][T] = p[N]-p[i]-1;
            if(res[i][T] < 0){
                puts("NO");
                fail = true;
            }
        }
        if(fail)
            continue;
        for(int i = 0; i < M; ++i){
            int id = N+i+1;
            if(matches[i].first==N || matches[i].second==N)
                continue;
            res[S][id] = 2;
            res[id][matches[i].first] = 2;
            res[id][matches[i].second] = 2;
        }
        int mf = 0;
        while(1){
            f = 0;
            memset(p,-1,sizeof(p));
            memset(vis,0,sizeof(vis));
            queue<int> q;
            vis[S] = true;
            q.push(S);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u==T)
                    break;
                for(auto i = res[u].begin(); i!=res[u].end(); i++){
                    if(i->second > 0 && !vis[i->first]){
                        vis[i->first]=true;
                        p[i->first] = u;
                        q.push(i->first);
                    }
                }
            }
            augment(T,INF);
            if(f==0)
                break;
            mf+=f;
        }
        if(mf == mcnt){
            for(int i = 0; i < M; ++i){
                int id = N+i+1;
                if(matches[i].second==N)
                    putchar('2');
                else if(matches[i].first==N)
                    putchar('0');
                else if(res[id][matches[i].second]==0)
                    putchar('2');
                else if(res[id][matches[i].first]==0)
                    putchar('0');
                else
                    putchar('1');
                putchar(' ');
            }
            putchar('\n');
        } else
            puts("NO");
    }
    return 0;
}
