#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

const int MX_N = 5555;
int N;
vector<int> adjList[MX_N];
int E[2*MX_N];
int H[MX_N];
int L[2*MX_N];
int P[MX_N];
int idx;

int SPT[3*MX_N][15];

void dfs(int ind, int depth,int parent){
    E[idx] = ind;
    L[idx] = depth;
    H[ind] = idx++;
    P[ind] = parent;
    for(vector<int>::iterator i = adjList[ind].begin(); i != adjList[ind].end(); i++){
        if(*i==parent)
            continue;
        dfs(*i,depth+1,ind);
        E[idx] = ind;
        L[idx++] = depth;
    }
}

void swap(int * a, int * b){
    int t = *a;
    *a = *b;
    *b = t;
}

int querySPT(int l, int r){
    if(l > r)
        swap(&l,&r);
    int k = (int) floor(log2(r-l+1));
    return (L[SPT[l][k]] < L[SPT[r-(1<<k)+1][k]]) ? SPT[l][k] : SPT[r-(1<<k)+1][k];
}

int main(){
    while(1){
        scanf("%d",&N);
        if(N==0)
            break;

        for(int i = 1; i <= N; i++)
            adjList[i].clear();
        memset(E,-1,sizeof(E));
        memset(H,-1,sizeof(H));
        memset(L,-1,sizeof(L));
        memset(P,-1,sizeof(P));
        idx = 0;

        int _a,_b;
        for(int i =0; i < N-1; i++){
            scanf("%d %d",&_a,&_b);
            adjList[_a].push_back(_b);
            adjList[_b].push_back(_a);
        }
        dfs(1,0,1);

        for(int i = 0; i < idx; i++)
            SPT[i][0] = i;
        for(int j = 1; (1<<j) <= idx; j++){
            for(int i = 0; i + (1<<j) <= idx; i++){
                if(L[SPT[i][j-1]] < L[SPT[i+(1<<(j-1))][j-1]])
                    SPT[i][j] = SPT[i][j-1];
                else
                    SPT[i][j] = SPT[i+(1<<(j-1))][j-1];
            }
        }

        int Q; scanf("%d", &Q);
        for(int i = 0; i < Q; i++){
            scanf("%d %d",&_a,&_b);
            int u = H[_a];
            int v = H[_b];
            if(u > v){
                swap(&u,&v);
                swap(&_a,&_b);
            }

            int ansInd = querySPT(u,v);
            int uDist = L[u]-L[ansInd];
            int vDist = L[v]-L[ansInd];
            int stepsToA = (uDist+vDist)/2;
            int stepsToB = (uDist+vDist+1)/2;
            if(uDist==vDist){
                printf("The fleas meet at %d.\n",E[ansInd]);
                continue;
            }
            int climber = (uDist > vDist) ? _a : _b;
            int a,b;
            a=b=climber;
            for(int i = 1; i <= stepsToB;i++){
                climber = P[climber];
                if(i==stepsToA)
                    a=climber;
                if(i==stepsToB)
                    b=climber;
            }
            if(a==b)
                printf("The fleas meet at %d.\n",a);
            else {
                if(a>b)
                    swap(&b,&a);
                printf("The fleas jump forever between %d and %d.\n",a,b);
            }
        }
    }
    return 0;
}
