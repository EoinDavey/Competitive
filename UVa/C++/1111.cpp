#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct point{
    double x,y;
    point(double _x, double _y) : x(_x), y(_y){}
    point(int _x, int _y) : x((double)_x), y((double)_y){}
    point(){}
};

point pivot;

double cross(point a, point b){
    return a.x * b.y - a.y * b.x;
}

bool ccw(point a, point b, point c){
    return cross(point(a.x-b.x, a.y - b.y),point(b.x - c.x, b.y - c.y)) >= 0;
}

double dist(point a, point b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

bool angleCmp(point a, point b){
    if(cross(point(a.x - pivot.x, a.y - pivot.y),point(b.x-pivot.x,b.y-pivot.y))==0) return dist(a,pivot) > dist(b,pivot);
    return atan2(a.y - pivot.y,a.x-pivot.x) < atan2(b.y - pivot.y, b.x - pivot.x);
}

int main(){
    int N;
    int caseNo = 1;
    while(scanf("%d",&N),N!=0){
        int tx,ty;
        vector<point> hull;
        vector<point> poly;
        for(int i = 0; i < N; i++){
            scanf("%d %d",&tx,&ty);
            poly.push_back(point(tx,ty));
        }
        int pos = 0;
        for(int i =0; i < N; i++)
            if(poly[i].y < poly[pos].y || (poly[i].y == poly[pos].y && poly[i].x > poly[pos].x))
                pos = i;
        point tp = poly[0];
        poly[0] = poly[pos];
        poly[pos] = tp;
        pivot = poly[0];
        sort(++poly.begin(), poly.end(), angleCmp);
        hull.push_back(poly[poly.size()-1]);
        hull.push_back(poly[0]);
        hull.push_back(poly[1]);
        for(int i = 2; i < poly.size();){
            if(ccw(hull[hull.size()-2],hull[hull.size()-1],poly[i]))
                hull.push_back(poly[i++]);
            else hull.pop_back();
        }
        double mn = 100000.0;
        double mx = 0;
        for(int i = 0; i < hull.size() -1; i++){
            mx = 0;
            for(int j = 0; j < hull.size(); j++){
                point ab(hull[i+1].x - hull[i].x, hull[i+1].y - hull[i].y);
                point ap(hull[j].x - hull[i].x, hull[j].y - hull[i].y);
                double u = (ab.x * ap.x + ab.y * ap.y)/(ab.x * ab.x + ab.y * ab.y);
                point c(hull[i].x + u*ab.x, hull[i].y + u*ab.y);
                double d = dist(hull[j],c);
                if(d > mx)mx = d;
            }
            if(mx < mn) mn = mx;
        }
        printf("Case %d: %.2lf\n",caseNo++,mn);
    }
    return 0;
}
