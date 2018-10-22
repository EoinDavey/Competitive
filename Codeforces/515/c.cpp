#include<bits/stdc++.h>
using namespace std;
const int MX_N = 400020;
int N;
int L, R;
int indMap[MX_N];

int main(){
    int n = 0;
    int Q; scanf("%d", &Q);
    char c; int d;
    while(Q-->0){
        scanf(" %c %d",&c,&d);
        if(c=='L'){
            indMap[d] = L;
            --L;
            ++n;
        } else if (c=='R') {
            indMap[d]=L+n+1;
            ++n;
        } else if (c=='?') {
            int ind = indMap[d];
            printf("%d\n", min(ind-L-1,n - 1 - (ind - L -1)));
        }
    }
    return 0;
}
