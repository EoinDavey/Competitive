#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define X(x) real(x)
#define Y(x) imag(x)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef complex<double> cc;
typedef vector<cc> poly;

double cross(cc& a, cc& b){
    return X(a) * Y(b) - Y(a) * X(b);
}

double area(poly& p){
    double sm = 0.0;
    for(int i = 0; i < p.size(); ++i){
	sm += cross(p[i], p[(i+1)%p.size()]);
    }
    return abs(sm)/2.0;
}

int main(){
    int N; cin >> N;
    double x, y;
    poly p;
    for(int i = 0; i < N; ++i){
	cin >> x >> y;
	x *= 1000.0;
	y *= 1000.0;
	p.pb({x,y});
    }
    p.pb(p[0]);
    cout << fixed << setprecision(10) << area(p)/1e6 << endl;
    return 0;
}
