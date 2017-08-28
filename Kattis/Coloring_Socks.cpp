#include<bits/stdc++.h>
using namespace std;

const int MX_S=100011;
int S,C,K;
int d[MX_S];

int main(){
    scanf("%d %d %d",&S,&C,&K);
    for(int i = 0; i < S; i++)
        scanf("%d",&d[i]);
    sort(d,d+S);
    int mn = d[0]; 
    int cnt = 0;
    int nMachines = 0;
    for(int i = 0; i < S; i++){
        if(cnt==C){
            nMachines++;
            cnt=0;
            mn = d[i];
        }
        if(d[i]-mn <= K){
            cnt++;
        } else {
            mn = d[i];
            cnt = 1;
            nMachines++;
        }
    }
    if(cnt > 0)
        nMachines++;
    printf("%d\n",nMachines);
    return 0;
}
