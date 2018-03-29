#include<bits/stdc++.h>
using namespace std;
const int MX_WL = 10001;
int t[MX_WL],N,W,L;

bool pos(int w){
    int lind = 0;
    int st = 1;
    for(int i = 0; i < L; ++i){
        if(lind < W){
            if(t[lind]<st+w){
                st = st+w;
                while(lind < W && t[lind] < st)
                    lind++;
            } else {
                st = t[lind];
            }
        } else {
            st = N+1;
        }
    }
    return st > N;
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        scanf("%d %d %d",&N,&W,&L);
        for(int i = 0; i < W; ++i)
            scanf("%d",&t[i]);
        sort(t,t+W);
        int l,r;
        l = 1, r = N;
        while(1){
            if(l==r)
                break;
            int md = (l+r)/2;
            if(pos(md)){
                r = md;
            } else {
                l = md+1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}
