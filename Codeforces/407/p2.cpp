#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long ll;

using namespace std;

ll b,q,l,m;

int main(){
    cin >> b >> q >> l >> m;
    ll a[m];
    if(abs(b)>l){
        printf("0");
        return 0;
    }
    bool ab = false;
    bool amb = false;
    bool a0 = false;
    for(int i = 0; i < m; i++)
        scanf("%lld",&a[i]);
    long long c = 0;
    for(int i= 0; i < 100; i++){
        if(abs(b) > l)
            break;
        else{
            bool br = false;
            for(int i = 0; i < m && !br; i++){
                if(a[i]==b)
                    br=true;
            }
            if(!br)
                c++;
        }
        b*=q;
    }
    if(c>=50)
        printf("inf\n");
    else
        printf("%lld\n",c);
    return 0;
}
