#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N,s,f,t,C;
int res[111][111];
int INF = 1000000;
vector<int> p;

void augment(int u, int minEdge){
    if(u==s){
        f = minEdge;
        return;
    }
    if(p[u]!=-1){
        augment(p[u],min(minEdge,res[p[u]][u]));
        res[p[u]][u]-=f;
        res[u][p[u]]+=f;
    }
}

int main(){
    int cnt = 0;
    while(cin >> N){
        if(N==0) break;
        printf("Network %d\n",++cnt);
        cin >> s >> t >> C;
        N++;
        int ia,ib,iw;
        memset(res,0,sizeof(res));
        for(int i = 0; i < C; i++){
            scanf("%d %d %d",&ia,&ib,&iw);
            res[ia][ib] = res[ib][ia] = res[ia][ib] + iw;
        }
        int mf = 0;
        while(1){
            f = 0;
            queue<int> q;
            p.assign(N,-1);
            vector<int> dist(N,INF);
            dist[s] = 0;
            q.push(s);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u==t) break;
                for(int i = 0; i< N; i++){
                    if(res[u][i] > 0 && dist[i]==INF){
                        dist[i] = dist[u] + 1;
                        p[i] = u;
                        q.push(i);
                    }
                }
            }
            augment(t,INF);
            if(f==0)
                break;
            mf+=f;
        }
        printf("The bandwidth is %d.\n\n",mf);
    }
    return 0;
}
