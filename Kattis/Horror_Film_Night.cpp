#include<bits/stdc++.h>
using namespace std;

const int MX_N = 1000001;

bool lk[MX_N][2];

bool vC(int i, int j){
    if(i==-1)
        return true;
    if(!lk[i][0] && !lk[j][0])
        return false;
    if(!lk[i][1] && !lk[j][1])
        return false;
    return true;
}

int main(){
    for(int k = 0; k < 2; ++k){
        int n;scanf("%d",&n);
        int in;
        for(int i = 0; i < n; ++i){
            scanf("%d",&in);
            lk[in][k]=true;
        }
    }
    int ln = 0;
    int prv = -1;
    for(int i = 0; i < MX_N; ++i){
        if(lk[i][0] || lk[i][1]){
            if(vC(prv,i)){
                ln++;
                prv = i;
            }
        }
    }
    printf("%d\n",ln);
    return 0;
}
