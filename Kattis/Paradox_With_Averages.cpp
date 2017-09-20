#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        int Ncs,Ne; scanf("%d %d",&Ncs,&Ne);
        ll cs[Ncs],e[Ne];
        for(int i = 0; i < Ncs; ++i)
            scanf("%lld",&cs[i]);
        for(int i = 0; i < Ne; ++i)
            scanf("%lld",&e[i]);
        double csa = 0.0;
        double ea = 0.0;
        for(int i = 0; i < Ncs; ++i)
            csa+=(double) cs[i];
        for(int i = 0; i < Ne; ++i)
            ea+=(double) e[i];
        csa/=(Ncs*1.0);
        ea/=(Ne*1.0);
        int cnt=0;
        for(int i = 0; i < Ncs; ++i)
            if(((double)cs[i]) < csa && ((double)cs[i]) > ea)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
