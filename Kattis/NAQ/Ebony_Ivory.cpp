#include<bits/stdc++.h>
using namespace std;
const int MX_SZ = 22;
const int B_SZ = 90;
const int INF = 1000*1000*1000;

//0 ww, 1 wb, 2 bw, 3 bb
map<int, map<int, vector<int> > > moves[4];

int ww,wb,bw,bb;
bool black[B_SZ];
string S;

int memo[5][10011];

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
    if(n1==n2)
        return f1==f2 ? 0 : INF;
    if(S[n1] < S[n2]){
        int mvInd = mvMap(n1,n2);
        int dist = S[n1]-S[n2];
        if(moves[mvInd].find(f1) != moves[mvInd].end()
                && moves[mvInd][f1].find(f2) != moves[mvInd][f1].end())
            return moves[mvInd][f1][f2][dist];
    } else {
        int mvInd = mvMap(n2,n1);
        int dist = S[n2]-S[n1];
        if(moves[mvInd].find(f2) != moves[mvInd].end()
                && moves[mvInd][f2].find(f1) != moves[mvInd][f2].end())
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
    scanf("%d %d %d %d",&sizes[0], sizes+1, sizes+2, sizes+3);
    int fl,fu,h;
    for(int k = 0; k < 4; ++k){
        for(int i = 0; i < ww; ++i){
            scanf("%d %d",&fl,&fu);
            vector<int> vi(13);
            vi[0] = fu;
            for(int j = 1; j <= 12; ++j){
                scanf("%d",&h);
                vi[j] = h;
            }
            if(moves[0].find(fl) == moves[0].end())
                moves[0][fl] = map<int, vector<int> >();
            moves[0][fl][fu] = vi;
        }
    }
    return 0;
}
