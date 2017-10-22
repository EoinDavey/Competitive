#include <bits/stdc++.h>
using namespace std;

struct point {
    int x,y;
    point(int _x, int _y) : x(_x), y(_y){}
    point(){}
    point operator+ (const point& p)const {
        return point(x+p.x,y+p.y);
    }
    point operator- (const point& p) const{
        return point(x-p.x,y-p.y);
    }
    bool operator== (const point& p) const {
        return x==p.x && y==p.y;
    }
};

constexpr int MX_N = 100001;
int N;
point vertices[MX_N];

double dist(const point& a, const point& b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

int cross(const point& a, const point& b){
    return a.x*b.y - a.y*b.x;
}

bool ccw(const point& a, const point& b, const point& c){
    if(a==b || b==c || a==c)
        return false;
    point u = b-c;
    point v = b-a;
    int cr = cross(u,v);
    return cr >= 0;
}

int dot(const point& a, const point& b){
    return a.x*b.x + a.y*b.y;
}

int norm_sq(const point& a){
    return  a.x*a.x + a.y*a.y;
}

double distToLine(const point& p, const point &a, const point& b){
    point ap = p-a;
    point ab = b-a;
    point c;
    double u = ((double) dot(ap,ab))/ ((double) norm_sq(ab));
    c = a + point(u*ab.x, u*ab.y);
    return dist(p,c);
}

int main() {
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d",&vertices[i].x,&vertices[i].y);
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
    putchar('\n');
    for(int i = 0; i < hull.size(); ++i)
        printf("%d %d\n",hull[i].x,hull[i].y);
    putchar('\n');
    for(int i = 0; i < hull.size()-1; ++i){
        printf("Edge (%d,%d), (%d,%d)\n",hull[i].x,hull[i].y,hull[i+1].x,hull[i+1].y);
        double mx = 0.0;
        for(int j = 0; j < N; ++j){
            double d = distToLine(vertices[j],hull[i],hull[i+1]);
            printf("D to (%d,%d)\n:%lf\n",vertices[j].x,vertices[j].y,d);
            mx = max(d,mx);
        }
        printf("mx %lf\n",mx);
        mn = min(mn,mx);
    }
    printf("%.7lf\n",mn);
    return 0;
}
