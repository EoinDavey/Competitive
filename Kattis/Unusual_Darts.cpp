#include<bits/stdc++.h>
#define x(a) real(a)
#define y(a) imag(a)
using namespace std;
typedef complex<double> pt;
typedef complex<double> vec;
typedef vector<pt> pgon;
typedef struct { pt p,q; } lseg;
const double EPS =1e-8;

double cross(const vec& a, const vec &b){ return x(a)*y(b)-y(a)*x(b); }
//cross product of (b-a) and (c-b), 0 is collinear
int orientation(const pt& a, const pt& b, const pt& c){
    double v = cross(b-a,c-b);
    if(abs(v-0.0)<EPS)
        return 0;
    return v > 0 ? 1 : 2;
}
bool intersects(const lseg& a, const lseg& b){
    if(a.q == b.p || b.q == a.p)
        return false;
    int o1 = orientation(a.p,a.q,b.p);
    int o2 = orientation(a.p,a.q,b.q);
    int o3 = orientation(b.p,b.q,a.p);
    int o4 = orientation(b.p,b.q,a.q);
    if(o1!=o2 && o3 != o4)
        return true;
    return false;
}

bool is_simple(const pgon& p){
    for(int i = 1; i < p.size(); ++i){
        lseg a{p[i-1],p[i]};
        for(int j = 1; j < i; ++j){
            lseg b{p[j-1],p[j]};
            if(intersects(a,b))
                return false;
        }
    }
    return true;
}

double area(const pgon& p){
    double area = 0.0;
    for(int i = 1; i < p.size(); ++i)
        area+=cross(p[i-1],p[i]);
    return abs(area)/2.0;
}

double prob_bob_win(const pgon& p){
    if(!is_simple(p))
        return 1.0;
    double r = area(p)/4.0;
    return r*r*r;
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        pgon p(7);
        for(int i = 0; i < 7; ++i){
            double x,y; scanf("%lf %lf",&x,&y);
            p[i] = {x,y};
        }
        double tp;scanf("%lf",&tp);
        int perm[] = {0,1,2,3,4,5,6};
        do {
            pgon np(8);
            for(int i = 0; i < 7; ++i){
                np[i] = p[perm[i]];
            }
            np[7] = np[0];
            double prob = prob_bob_win(np);
            if(abs(prob-tp)<1e-5){
                for(int j = 0;j < 7; ++j)
                    printf("%d ",perm[j]+1);
                putchar('\n');
                break;
            }
        } while(next_permutation(perm,perm+7));
    }
    return 0;
}
