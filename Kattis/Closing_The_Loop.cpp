#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int t = 0; t < T;t++){
        int N; scanf("%d",&N);
        vector<int> B,R;
        int _i;char _c;
        for(int i =0; i < N; i++){
            scanf(" %d%c",&_i,&_c);
            if(_c=='R'){
                R.push_back(_i);
            }
            if(_c=='B'){
                B.push_back(_i);
            }
        }
        sort(B.begin(),B.end(),greater<int>());
        sort(R.begin(),R.end(),greater<int>());
        int l = min(B.size(),R.size());
        int sm=0;
        for(int i = 0; i < l; i++){
            sm+=B[i]+R[i];
        }
        printf("Case #%d: %d\n",t+1,sm-2*l);
    }
    return 0;
}
