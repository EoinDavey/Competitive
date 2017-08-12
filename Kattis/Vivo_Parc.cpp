#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

const int MX_N = 100;
bool adjMat[MX_N][MX_N];
int N;
int colour[MX_N];

bool check(int u, int c){
    for(int v = 0; v < N; v++)
        if(adjMat[u][v] && colour[v]==c)
                return false;
    return true;
}

bool solve(int u){
    if(u==N)
        return true;
    for(int c = 0; c < 4; c++){
        if(check(u,c)){
            colour[u]=c;
            if(solve(u+1))
                return true;
            colour[u]=-1;
        }
    }
    return false;
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        colour[i]=-1;
    int a,b;
    while(scanf("%d-%d",&a,&b)==2){
        a--;b--;
        adjMat[a][b]=adjMat[b][a]=true;
    }
    for(int i = 0; i < N; i++)
        if(colour[i]==-1){
            solve(i);
        }
    for(int i = 0; i < N; i++)
        printf("%d %d\n",i+1,colour[i]+1);
    return 0;
}
