#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 100001,INF=300000000;
int N,cnt[3],s[3],c[MX_N];

int ord[][2] = {{0,0},{0,1},{0,2},{1,1},{1,2},{2,2}};

bool check(int v){
    int lcnt[] = {cnt[0],cnt[1],cnt[2]};
    for(int i=0; i < N; ++i){
        int mncst = INF;
        int ans = 0;
        for(int k = 0; k < 6; ++k){
            lcnt[ord[k][0]]--;
            lcnt[ord[k][1]]--;
            if(lcnt[0] >= 0 && lcnt[1] >= 0 && lcnt[2] >= 0){
                int cst = c[i] * (s[ord[k][0]] + s[ord[k][1]]);
                if(cst >= v && cst < mncst){
                    mncst = cst;
                    ans = k;
                }
            }
            lcnt[ord[k][0]]++;
            lcnt[ord[k][1]]++;
        }
        if(mncst==INF)
            return false;
        lcnt[ord[ans][0]]--;
        lcnt[ord[ans][1]]--;
    }
    return true;
}

int main(){
    scanf("%d %d %d",&cnt[0],&cnt[1],&cnt[2]);
    scanf("%d %d %d",&s[0],&s[1],&s[2]);
    N=(cnt[0]+cnt[1]+cnt[2])/2;
    for(int i = 0;i < N; ++i)
        scanf("%d",&c[i]);
    sort(c,c+N);
    int L = 2; int R = INF;
    int lcnt = 0;
    while(1){
        if(L >= R || lcnt >= 40)
            break;
        int md = (L+R)/2;
        if(check(md)){
            L = md;
        } else {
            R = md-1;
        }
        lcnt++;
    }
    if(check(R))
        printf("%d\n",R);
    else
        printf("%d\n",L);
    return 0;
}
