#include<bits/stdc++.h>
using namespace std;
const int MX_SZ = 22;
const int B_SZ = 90;
const int INF = 1000*1000;

//0 ww, 1 wb, 2 bw, 3 bb
vector<int> moves[4][10][10];

int ww,wb,bw,bb, L;
bool black[B_SZ];
vector<int> S;

int memo[10][10011];

int mvMap(int a, int b){
    if(black[S[a]]){
        if(black[S[b]])
            return 3;
        return 2;
    }
    if(black[S[b]])
        return 1;
    return 0;
}

int cost(int n1, int n2, int f1, int f2){
    if(S[n1]==S[n2])
        return f1==f2 ? 0 : INF;
    if(S[n1] < S[n2]){
        int mvInd = mvMap(n1,n2);
        int dist = S[n2]-S[n1];
        if(moves[mvInd][f1][f2].size() > 1)
            return moves[mvInd][f1][f2][dist];
    } else {
        int mvInd = mvMap(n2,n1);
        int dist = S[n1]-S[n2];
        if(moves[mvInd][f2][f1].size() > 1)
            return moves[mvInd][f2][f1][dist];
    }
    return INF;
}

int dp(int cf, int pos){
    if(pos >= L-1)
        return 0;
    if(memo[cf][pos]!=-1)
        return memo[cf][pos];
    int mn = INF;
    for(int i = 1; i <= 5; ++i){
        mn = min(mn, cost(pos,pos+1,cf,i) + dp(i,pos+1));
    }
    return memo[cf][pos] = mn;
}

int main(){
    memset(memo,-1,sizeof(memo));
    black[2]=black[5]=black[7]=black[10]=black[12] = true;
    for(int i = 0; i < B_SZ; ++i){
        if(black[i] && i + 12 < B_SZ)
            black[i+12]=true;
    }
    int sizes[4];
    scanf("%d %d %d %d %d",&sizes[0], sizes+1, sizes+2, sizes+3, &L);
    int fl,fu,h;
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < sizes[k]; ++i){
            scanf("%d %d",&fl,&fu);
            vector<int> vi(13);
            for(int j = 1; j <= 12; ++j){
                scanf("%d",&h);
                vi[j] = h;
            }
            moves[k][fl][fu] = vi;
        }
    }
    for(int i = 0; i < L; ++i){
        scanf("%d",&h);
        S.push_back(h);
    }
    int mn = INF;
    for(int i = 1; i<=5; ++i)
        mn = min(mn, dp(i,0));
    printf("%d\n", mn);
    return 0;
}
