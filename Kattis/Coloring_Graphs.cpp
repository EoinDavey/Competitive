#include<bits/stdc++.h>
using namespace std;

const int MX_N = 12,INF=1000;
vector<int> adjList[MX_N];
int N;
int colour[MX_N];

bool check(int u, int c){
    for(auto v = adjList[u].begin(); v != adjList[u].end(); v++)
        if(colour[*v]==c)
                return false;
    return true;
}

bool solve(int u,int lm){
    if(u==N)
        return true;
    for(int c = 0; c < lm; c++){
        if(check(u,c)){
            colour[u]=c;
            if(solve(u+1,lm))
                return true;
            colour[u]=-1;
        }
    }
    return false;
}

int main(){
    scanf("%d",&N);
    int x;
    string in;
    getline(cin,in);
    memset(colour,-1,sizeof(colour));
    for(int i = 0; i < N; i++){
        getline(cin,in);
        stringstream ss(in);
        while(ss >> x){
            adjList[x].push_back(i);
            adjList[i].push_back(x);
        }
    }
    for(int i = 1; i <= N; i++){
        if(solve(0,i)){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
