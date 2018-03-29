#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MX_N = 100002;
const ll INF = 1000000000000;
int N;
ll ls[MX_N];
int L[MX_N];
ll I[MX_N];

void nlogn(){
    for(int i = 1; i < N+1; ++i)
        I[i]=INF;
    I[0] = -INF;
    int mx = 1;
    for(int i = 0; i < N; ++i){
        int ind = lower_bound(I,I+N+1,ls[i]) - I;
        I[ind] = ls[i];
        L[i] = ind;
        mx = max(mx,ind);
    }
    printf("%d\n",mx);
    ll prv = INF;
    vector<int> out;
    for(int i = N-1; i >= 0; --i){
        if(ls[i] < prv && L[i]==mx){
            out.push_back(i);
            prv = ls[i];
            mx--;
        }
    }
    for(auto i = out.rbegin(); i != out.rend(); i++)
        printf("%d ",*i);
    putchar('\n');
}

int main(){
    while(~scanf("%d",&N)){
        for(int i = 0; i < N; ++i){
            scanf("%lld",&ls[i]);
        }
        //printf("%d\n",dpLIS());
        //printf("%d\n",nlogn());
        nlogn();
    }
    return 0;
}
