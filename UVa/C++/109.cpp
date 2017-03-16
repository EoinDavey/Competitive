#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

struct point{
    int x,y;
    point(){}
    point(int _x, int _y) : x(_x), y(_y){}
};

point pivot;
vector<vector<point> > polygons;
vector<vector<point> > hulls;

int cross(point a, point b){
    return (a.x * b.y) - (b.x * a.y);
}

bool ccw(point a, point b, point c){
    return cross(point(a.x - b.x, a.y - b.y), point(b.x - c.x, b.y - c.y)) >= 0;
}

double dist(point a, point b){
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}

bool angleCmp(point a, point b){
    if(cross(point(a.x-pivot.x,a.y-pivot.y), point(b.x - pivot.x, b.y - pivot.y))==0) return dist(a,pivot) > dist(b,pivot);
    return atan2(a.y - pivot.y, a.x - pivot.x) < atan2(b.y - pivot.y, b.x - pivot.x);
}

double angle(point a, point o, point b){
    point oa = point(a.x - o.x, a.y - o.y);
    point ob = point(b.x - o.x, b.y - o.y);
    return acos(((double)(oa.x * ob.x + oa.y * ob.y))/(sqrt(pow(oa.x,2) + pow(oa.y,2)) * sqrt(pow(ob.x,2) + pow(ob.y,2))));
}

int main(){
    int N, _N, _x, _y;
    N=0;
    while(scanf("%d",&_N),_N!=-1){
        N++;
        vector<point> _poly;
        for(int i = 0; i < _N; i++){
            scanf("%d %d",&_x,&_y);
            _poly.push_back(point(_x,_y));
        }
        int _pos = 0;
        for(int i = 0; i < _N; i++){
            if(_poly[i].y < _poly[_pos].y || (_poly[i].y == _poly[_pos].y && _poly[i].x > _poly[_pos].x))
                _pos = i;
        }
        point _point = _poly[0];
        _poly[0] = _poly[_pos];
        _poly[_pos] = _point;
        pivot = _poly[0];
        sort(++_poly.begin(), _poly.end(), angleCmp);
        polygons.push_back(_poly);
        for(int i = 0; i < _N; i++){
            //printf("(%d,%d)\n",_poly[i].x, _poly[i].y);
        }
    }
    for(int i = 0; i < N; i++){
        vector<point> _hull;
        int _N = polygons[i].size();
        _hull.push_back(polygons[i][_N-1]);
        _hull.push_back(polygons[i][0]);
        _hull.push_back(polygons[i][1]);
        for(int j = 2; j < _N;){
            int _t = _hull.size();
            if(ccw(_hull[_t-2], _hull[_t-1], polygons[i][j]))
                _hull.push_back(polygons[i][j++]);
            else
                _hull.pop_back();
        }
        hulls.push_back(_hull);
    }
    int mX,mY;
    bool stations[N];
    memset(stations,true,sizeof(stations));
    double totArea = 0.0;
    while(scanf("%d %d",&mX,&mY) == 2){
        //printf("firing missile (%d,%d)\n",mX,mY);
        point pt(mX,mY);
        for(int i = 0; i < N; i++){
            //printf("checking country %d\n",i);
            double sum = 0;
            for(int j = 0; j < hulls[i].size() -1; j++){
                double ang = angle(hulls[i][j],pt,hulls[i][j+1]);
                //printf("angle (%d,%d) -> (%d,%d) -> (%d,%d) : %lf\n",hulls[i][j].x,hulls[i][j].y,pt.x,pt.y,hulls[i][j+1].x,hulls[i][j+1].y,ang);
                if(ccw(pt, hulls[i][j],hulls[i][j+1]))
                    sum+=ang;
                else sum-=ang;
            }
            //printf("Sum Angle:%lf\n",sum);
            if(fabs(fabs(sum) - 2*M_PI) < 0.0001){
                //printf("hit\n");
                double _a = 0.0;
                for(int j = 0; j < hulls[i].size()-1; j++){
                    _a += (hulls[i][j].x * hulls[i][j+1].y) - (hulls[i][j].y * hulls[i][j+1].x);
                }
                _a/=2.0;
                if(stations[i]){
                    stations[i]=false;
                    totArea += fabs(_a);
                }
                break;
            }
        }
    }
    printf("%.2lf\n",totArea);
    return 0;
}
