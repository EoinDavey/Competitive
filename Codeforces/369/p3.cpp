#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int N,M,K;
int tree[102];
long long int p[102][102];
long long int memo[102][102][102];

void printD(int d){
    for(int j = 0; j < d;j++){
        cout << "  ";
    }
}

long long int dp(int beaut, int pos, int c, int d){
    /*printD(d);
    printf("B:%d, P:%d, C:%d\n",beaut,pos,c);
    printD(d);
    printf("memo:%d\n",memo[beaut][pos][c]);*/
    if(beaut==K&&pos==N)return 0;
    if(beaut>K||pos==N||c>M)return -1;
    if(memo[beaut][pos][c]!=-2)return memo[beaut][pos][c];
    long long int cost=-1LL;
    if(tree[pos]!=0LL){
        if(c==tree[pos]){
            cost=dp(beaut,pos+1,c,d+1);
        }else{
            cost = dp(beaut+1,pos+1,tree[pos],d+1);
        }
    } else {
        for(int i = 1; i <= M;i++){
            //printD(d);
            //printf("Painting with %d\n",i);
            long long int o = dp((beaut + ((c==i)?0LL:1LL)),pos+1,i,d+1);
            if((o+p[pos][i]<cost||cost==-1LL)&&o!=-1LL)cost = o + p[pos][i];
            //printD(d);
            //printf("O: %d, Cost:%d\n",o,o+p[pos][i]);
        }
    }
    //printD(d);
    //printf("Min Cost:%d\n",cost);
    return memo[beaut][pos][c] = cost;
}

int main(){
    cin >> N>>M>>K;
    for(int i = 0; i < N;i++){
        scanf("%d",&tree[i]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= M;j++){
            scanf("%l64d",&p[i][j]);
        }
    }
    for(int i = 0; i <= K; i++){
        for(int j = 0; j < N;j++){
            for(int k = 0; k<=M;k++){
                memo[i][j][k]=-2;
	        }
        }
    }
    cout << dp(0,0,0,0) << endl;;
    return 0;
}
