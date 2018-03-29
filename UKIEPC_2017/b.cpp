#include <bits/stdc++.h>
using namespace std;

struct point {
    double x,y;
    point(double _x, double _y) : x(_x), y(_y){}
    point(){}

    point operator+ (const point& p) const{
        return point(x+p.x,y+p.y);
    }

    point operator- (const point& p) const{
        return point(x-p.x,y-p.y);
    }

    bool operator== (const point& p) const {
        return x==p.x && y==p.y;
    }
};

point anchor;
constexpr int MX_N = 100001;
int N;
point vertices[MX_N];

double dist(const point& a, const point& b){
    return hypot(a.x-b.x,a.y-b.y);
}

double cross(const point& a, const point& b){
    return a.x*b.y - a.y*b.x;
}

bool ccw(const point& a, const point& b, const point& c){
    if(a==b || b==c || a==c)
        return false;
    point u = b-c;
    point v = b-a;
    double cr = cross(u,v);
    return cr >= 0.0;
}

bool angleCmp(const point& a, const point& b){
    point relA = a-anchor;
    point relB = b-anchor;
    if(cross(relA,relB)==0)
        return dist(a,anchor) > dist(b,anchor);
    return atan2(relA.y,relA.x) < atan2(relB.y, relB.x);
}

double dot(const point& a, const point& b){
    return a.x*b.x + a.y*b.y;
}

double norm_sq(const point& a){
    return a.x*a.x + a.y*a.y;
}

double distToLine(const point& p, const point &a, const point& b){
    point ap = p-a;
    point ab = b-a;
    point c;
    double u = dot(ap,ab)/ norm_sq(ab);
    c = a + point(u*ab.x, u*ab.y);
    return dist(p,c);
}

int main() {
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%lf %lf",&vertices[i].x,&vertices[i].y);
    int pos = 0;
    for(int i = 0; i < N; i++)
        if(vertices[i].y < vertices[pos].y || (vertices[i].y==vertices[pos].y && (vertices[i].x > vertices[pos].x)))
            pos = i;
    point _tp = vertices[0];
    vertices[0] = vertices[pos];
    vertices[pos] = _tp;
    anchor = vertices[0];
    sort(vertices+1,vertices+N, angleCmp);
    vector<point> hull;
    hull.push_back(vertices[N-1]);
    hull.push_back(vertices[0]);
    hull.push_back(vertices[1]);
    for(int i = 2; i < N;){
        int t = hull.size();
        if(ccw(hull[t-2],hull[t-1],vertices[i]))
            hull.push_back(vertices[i++]);
        else
            hull.pop_back();
    }
    double mn = 1000000000.0;
    for(int i = 0; i < hull.size()-1; ++i){
        double mx = 0.0;
        for(int j = 0; j < N; ++j){
            double d = distToLine(vertices[j],hull[i],hull[i+1]);
            mx = max(d,mx);
        }
        mn = min(mn,mx);
    }
    printf("%.7lf\n",mn);
    return 0;
}
