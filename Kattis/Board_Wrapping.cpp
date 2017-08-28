#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;

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

double dist(point a, point b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

double dot(point a, point b){
    return a.x*b.x + a.y*b.y;
}

double cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}

bool angleCmp(point a, point b){
    point relA = a-anchor;
    point relB = b-anchor;
    if(cross(relA,relB)==0)
        return dist(a,anchor) > dist(b,anchor);
    return atan2(relA.y,relA.x) < atan2(relB.y, relB.x);
}

bool ccw(point a, point b, point c){
    point u = b-c;
    point v = b-a;
    double cr = cross(u,v);
    return cr > 0.0 || abs(cr-0.0) < EPS;
}

int main(){
    int T; scanf("%d\n",&T);
    while(T-->0){
        vertices.clear();
        scanf("%d",&N);
        double x,y,w,h,v;
        double tArea = 0.0;
        for(int i = 0; i < N; i++){
            scanf("%lf %lf %lf %lf %lf",&x,&y,&w,&h,&v);
            cc center(x,y);
            cc mv1 = polar(h/2.0,(90.0-v)*(M_PI/180.0));
            cc mv2 = polar(w/2.0,v*(-M_PI/180.0));
            cc corners[4] = {center+mv1+mv2,center+mv1-mv2,center-mv1+mv2,center-mv1-mv2};
            for(int j = 0; j < 4; j++)
                vertices.push_back(point(real(corners[j]),imag(corners[j])));
            tArea+=w*h;
        }
        int pos = 0;
        for(int i = 0; i < vertices.size(); i++)
            if(vertices[i].y < vertices[pos].y || (vertices[i].y==vertices[pos].y && (vertices[i].x > vertices[pos].x)))
                pos = i;
        point _tp = vertices[0];
        vertices[0] = vertices[pos];
        vertices[pos] = _tp;
        anchor = vertices[0];
        sort(++vertices.begin(),vertices.end(), angleCmp);
        vector<point> hull;
        hull.push_back(vertices[vertices.size()-1]);
        hull.push_back(vertices[0]);
        hull.push_back(vertices[1]);
        for(int i = 2; i < vertices.size();){
            int t = hull.size();
            if(ccw(hull[t-2],hull[t-1],vertices[i]))
                hull.push_back(vertices[i++]);
            else
                hull.pop_back();
        }
        double area = 0.0;
        for(int i = 0; i < hull.size()-1; i++){
            area+=cross(hull[i],hull[i+1]);
        }
        area/=2.0;
        printf("%.1lf %%\n",100.0*tArea/area);
    }
    return 0;
}
