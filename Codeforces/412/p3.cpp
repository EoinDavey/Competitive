#include<iostream>
#include<cstdio>
#include<cmath>

typedef long long ll;

using namespace std;

ll x, y, d;

void euclid(ll a, ll b){
    if (b==0){
        x = 1;
        y = 0;
        d = a;
        return;
    }
    euclid(b, a % b);
    ll x1 = y;
    ll y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

int main(){
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        ll X,Y,P,Q; cin >> X >> Y >> P >> Q;
        if(P==Q && X!=Y){
            printf("-1\n");
            continue;
        }
        if(X==0 && Y==0){
            printf("%lld\n",Q);
            continue;
        }
        if(P==0){
            if(X==0)
                printf("0\n");
            else
                printf("-1\n");
            continue;
        }
        euclid(Q,-P);
        ll c = P*Y - X*Q;
        x*=(c/d), y*=(c/d);
        d=1;
        double uLim = x*(1.0/((double)-P));
        double bLim = y*(1.0/((double)-Q));
        double lim3 = ((double)x - y)/((double)Q-P);
        printf("%lf %lf %lf\n",uLim,bLim,lim3);
        ll n = (ll) ceil(max(uLim,max(bLim,lim3)));
        ll xn = x + (P)*n; ll yn = y + (Q)*n;
        printf("%lld %lld\n",xn,yn);
        printf("%lld\n",yn);
    }
    return 0;
}
