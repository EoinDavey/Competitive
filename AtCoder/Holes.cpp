#include<bits/stdc++.h>
using namespace std;
typedef complex<double> point;

constexpr int MX_N=101;
int N;
point V[MX_N];
int perm[MX_N];
double out[MX_N];

double cross(const point& a, const point& b){
    return real(a)*imag(b) - imag(a)*real(b);
}

bool ccw(const point& a,const point& b, const point& c){
    if(a==b || b==c || a==c)
        return false;
    point u = b-c;
    point v = b-a;
    double cr = cross(u,v);
    return cr > 0;
}

int main(){
    scanf("%d",&N);
    double x,y;
    for(int i = 0; i < N; i++){
        scanf("%lf %lf",&x,&y);
        V[i]=point(x,y);
        perm[i]=i;
    }
    sort(perm,perm+N,
            [](int a, int b){
                const point &pa = V[a];
                const point &pb = V[b];
                if(real(pa)!=real(pb))
                    return real(pa) < real(pb);
                return imag(pa) < imag(pb);
            });
    vector<int> L;
    vector<int> U;
    for(int i = 0; i < N;){
        int t = L.size();
        if(t >= 2 && !ccw(V[L[t-2]],V[L[t-1]],V[perm[i]]))
            L.pop_back();
        else
            L.push_back(perm[i++]);
    }
    for(int i = N-1; i >=0;){
        int t = U.size();
        if(t >= 2 && !ccw(V[U[t-2]],V[U[t-1]],V[perm[i]]))
            U.pop_back();
        else
            U.push_back(perm[i--]);
    }
    vector<int> hull;
    for(int i = 0; i < L.size()-1; ++i)
        hull.push_back(L[i]);
    for(int i = 0; i < U.size()-1; ++i)
        hull.push_back(U[i]);
    int h = hull.size();
    if(h == 2){
        out[hull[0]] = out[hull[1]] = 0.5;
    } else {
        for(int i = 0;i < h; ++i){
            point a = V[hull[(h+(i-1))%h]];
            point b = V[hull[i]];
            point c = V[hull[(i+1)%h]];
            point ab = (b-a)*point(0,1);
            point cb = (b-c)*point(0,-1);
            double ang = abs(arg(ab)-arg(cb))/(2*M_PI);
            out[hull[i]] = min(1-ang,ang);
        }
    }
    for(int i = 0; i < N; ++i){
        printf("%.16lf\n",out[i]);
    }
    return 0;
}
