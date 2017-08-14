#include<bits/stdc++.h>
using namespace std;

const int MX_N = 10001;
bool up[MX_N];
int N,M,L;
vector<int> adjList[MX_N];
int tot;

void dfs(int u){
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%d %d %d",&N,&M,&L);
        N++;
        for(int i = 0;i < N;i++){
            up[i]=true;
            adjList[i].clear();
        }
        int x,y;
        for(int i = 0; i < M; i++){
            scanf("%d %d",&x,&y);
            adjList[x].push_back(y);
        }
        memset(up,1,sizeof(up));
        tot=0;
        int z;
        stack<int> st;
        for(int i = 0; i < L; i++){
            scanf("%d",&z);
            st.push(z);
        }
        while(!st.empty()){
            int v = st.top(); st.pop();
            if(!up[v])
                continue;
            up[v]=false;
            tot++;
            for(auto i = adjList[v].begin();i != adjList[v].end(); i++){
                if(up[*i])
                    st.push(*i);
            }
        }
        printf("%d\n",tot);
    }
    return 0;
}
