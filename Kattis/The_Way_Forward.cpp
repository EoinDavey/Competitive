#include<bits/stdc++.h>
using namespace std;
const int MX_N = 5005;
int xs[MX_N];
int N;

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)scanf("%d",&xs[i]);
    int run = 1;
    int mx = 0;
    for(int i = 1; i < N; ++i){
        if(xs[i] > xs[i-1])
            ++run;
        else{
            mx = max(run,mx);
            run = 1;
        }
    }
    mx = max(run,mx);
    printf("%d\n",mx);
    return 0;
}
