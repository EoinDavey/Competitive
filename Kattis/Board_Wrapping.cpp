#include<bits/stdc++.h>
using namespace std;

const double EPS = 10e-7;

struct point {
    double x,y;
    point(double _x, double _y) : x(_x), y(_y) {}
    point() {}

    point operator + (const point &p){
        return point(x+p.x,y+p.y);
    }

    point operator - (const point &p){
        return point(x-p.x,y-p.y);
    }

    bool operator == (const point &p){
        return abs(x-p.x) < EPS && abs(y-p.y) < EPS;
    }
};

point anchor;
const int MX_N=606;
int N;
vector<point> vertices;

bool angleCmp(point a, point b){
    return ang2anchor(a) < ang2anchor2(b);
}

double dot(point a, point b){
    return a.x*b.x + a.y*b.y;
}

double cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}

double ang2anchor(point a){
    return atan2(a.y-anchor.y, a.x-anchor.x);
}

bool ccw(point a, point b, point c){
    point u = b-c;
    point v = b-a;
    return cross(u,v) > 0;
}

int main(){
    scanf("%d",&N);
    double x,y,w,h,v;
    for(int i = 0; i < N; i++){
        scanf("%lf %lf %lf %lf %lf",&x,&y,&w,&h,&v);
    }
    return 0;
}
