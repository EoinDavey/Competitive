#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX_N=66;
int N;
char * a,* b;

ll ind(int n, char * s){
    if(n==1){
        return (ll) *s == '1';
    }
    if(*s=='1'){
        return (1L<<n)-ind(n-1,s+1)-1L;
    }
    return ind(n-1,s+1);
}

int main(){
    a = new char[MX_N];
    b = new char[MX_N];
    scanf("%d %s %s",&N,a,b);
    printf("%lld\n",ind(N,b)-ind(N,a)-1);
    delete a;
    delete b;
    return 0;
}
