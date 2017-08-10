#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

const int MX_N = 18;
const int MX_T = 3606;
int b[MX_N];
int v[MX_T];

struct path {
    int s,d;
    path(int _s, int _d) : s(_s), d(_d) {}
};

int val(int x){ return max(min(x,3600),0);}

int main(){
    int Q; scanf("%d",&Q);
    while(Q --> 0){
        int N,T;scanf("%d %d",&N,&T);
        for(int i = 0; i < N; i++)
            scanf("%d",&b[i]);
        memset(v,-1,sizeof(v));
        queue<path> q;
        q.push(path(val(0),0));
        while(!q.empty()){
            path p = q.front(); q.pop();
            if(v[val(p.s)]!=-1)
                continue;
            v[val(p.s)]=p.d;
            for(int i = 0; i < N; i++){
                if(v[val(p.s+b[i])]!=-1)
                    continue;
                q.push(path(val(p.s+b[i]),p.d+1));
            }
        }
        int ans = 0;
        for(int i = T; i <= 3600; i++){
            if(v[val(i)]!=-1){
                ans=i;
                break;
            }
        }
        printf("%d %d\n",v[val(ans)],ans-T);
    }
    return 0;
}
