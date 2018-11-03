#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
typedef complex<int> cc;
const int MX_N = 200002;
cc sum[MX_N];
int N;
cc fin;

inline cc mvC(char c){
    if(c=='U')
        return {0,1};
    if(c=='D')
        return {0,-1};
    if(c=='L')
        return {-1,0};
    return {1,0};
}

inline int dist(cc& x, cc& y){
    return abs(real(x)-real(y)) + abs(imag(x)-imag(y));
}

bool checkInd(int L, int ln){
    int R = L+ln-1;
    if(R >= N)
        return false;
    cc pos = sum[N-1] - ((R >= 0 ? sum[R] : cc{0,0}) - (L > 0 ? sum[L-1] : cc{0,0}));
    if(dist(pos,fin) <= ln && (ln-dist(pos,fin))%2==0)
        return true;
    return false;
}

bool checkList(int ln){
    for(int i = 0; i < N; ++i){
        if(i + ln - 1 >= N)
            break;
        if(checkInd(i,ln))
            return true;
    }
    return false;
}

int main(){
    scanf("%d",&N);
    char c;
    for(int i = 0; i < N; ++i){
        scanf(" %c",&c);
        cc mv = mvC(c);
        if(i == 0)
            sum[i] = mv;
        else
            sum[i] = mv + sum[i-1];
    }
    int x,y; scanf("%d %d", &x, &y);
    fin = {x,y};
    int L = 0; int R = N;
    while(L < R){
        int md = (L+R)/2;
        if(checkList(md)){
            R = md;
        } else {
            L = md+1;
        }
    }
    if(checkList(L))
        printf("%d\n",L);
    else
        puts("-1");
    return 0;
}
