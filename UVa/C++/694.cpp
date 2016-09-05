#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int A,L;

int main(){
    int t=1;
    while(scanf("%d %d",&A,&L)==2){
        if(A<0&&L<0)break;
        int a,l;
        a=A;
        int ct = 1;
        while(A!=1){
            if((A&1)==0){
                A=A>>1;
                ct++;
            } else {
                if(3*A+1>L || 3*A+1 <= A)break;
                A=3*A+1;
                ct++;
            }
        }
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",t,a,L,ct);
        t++;
    }
    return 0;
}
