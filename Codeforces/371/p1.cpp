#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

long long int l1,r1,l2,r2,k;

int main(){
    scanf("%lld %lld %lld %lld %lld",&l1,&r1,&l2,&r2,&k);
    //printf("%lld %lld %lld %lld %lld\n",l1,r1,l2,r2,k);
    long long int time;
    if(l2>r1||r2<l1){
        time = 0;
    }else{
        long long int l,r;
        l = max(l1,l2);
        r = min(r1,r2);
        time = r-l+1;
        if(k >= l && k<=r)time--;
    }
    cout << time << endl;
    return 0;
}
