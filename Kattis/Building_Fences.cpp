#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MX_N = 10000;
int N,K;
int p[MX_N];

bool achievable(double L){
    int cnt=0;
    for(int i = 0; i < K; i++)
        cnt+=((int) (1.0*p[i])/L);
    return cnt>=N;
}

int main(){
    while(scanf("%d %d",&K,&N)==2){
        for(int i = 0; i < K; i++)
            scanf("%d",&p[i]);
        double l=0,r=N;  
        double mx;  
        while(r-l>=1e-8){  
            double mid=(l+r)/2.0;  
            if(achievable(mid))  
                l=mid;  
            else  
                r=mid;  
                mx=mid;  
        }
        int ans=0;  
        for(int i=0;i<K;i++){  
            int pp=(int)(1.0*p[i]/mx);  
            if(fabs(1.0*pp*mx-p[i])<=1e-5) pp--;  
            ans+=pp;  
        }  
        printf("%d\n",ans);
    }
    return 0;
}
