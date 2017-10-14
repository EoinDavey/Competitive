#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
    point(int _x, int _y) : x(_x), y(_y) {}
    point() {}

    point operator+ (const point &p){
        return point(x+p.x,y+p.y);
    }

    point operator- (const point &p) const{
        return point(x-p.x,y-p.y);
    }

    bool operator== (const point& p) const {
        return x==p.x && y==p.y;
    }
};

point anchor;
constexpr int MX_N=100001;
int N;
point vertices[MX_N];

double dist(const point& a, const point& b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

int cross(const point& a, const point& b){
    return a.x*b.y - a.y*b.x;
}

bool angleCmp(const point& a, const point& b){
    point relA = a-anchor;
    point relB = b-anchor;
    if(cross(relA,relB)==0)
        return dist(a,anchor) > dist(b,anchor);
    return atan2(relA.y,relA.x) < atan2(relB.y, relB.x);
}

bool ccw(const point& a,const point& b, const point& c){
    if(a==b || b==c || a==c)
        return false;
    point u = b-c;
    point v = b-a;
    int cr = cross(u,v);
    return cr >= 0;
}

int main(){
    scanf("%d",&N);
    int x,y;
    for(int i = 0; i < N; i++)
        scanf("%d %d",&vertices[i].x,&vertices[i].y);
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
    double mx = 0.0;
    int t = hull.size();
    for(int i = 0; i < t; ++i)
        for(int j = i+1; j < t; ++j)
            mx = max(dist(hull[i],hull[j]),mx);
    printf("%.7lf\n",mx);
    return 0;
}
