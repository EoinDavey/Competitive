#include<bits/stdc++.h>
using namespace std;

const double EPS = 10e-6;

struct point {
    int x,y;
    point(int _x, int _y) : x(_x), y(_y) {}
    point():x(0), y(0){}

    point operator + (const point &p) {
        return point(x+p.x,y+p.y);
    }

    point operator - (const point &p) {
        return point(x-p.x,y-p.y);
    }

    bool operator == (const point &p) {
        return abs(x-p.x) < EPS && abs(y-p.y) < EPS;
    }
};

int N;
point tri[3];
double arT;

double area(point a, point b, point c){
    return abs(a.x*(b.y-c.y) + b.x*(c.y - a.y) + c.x*(a.y-b.y))/2.0;
}

bool inTri(point u){
    double ar = 0.0;
    for(int i = 0; i < 3; i++){
        ar += area(u,tri[(i+1)%3],tri[i]);
    }
    return abs(arT-ar) < EPS;
}

int main(){
    for(int i = 0; i < 3; i++)
        scanf("%d %d",&tri[i].x,&tri[i].y);
    scanf("%d",&N);
    int cnt=0;
    arT = area(tri[0],tri[1],tri[2]);
    printf("%.1lf\n",arT);
    point tree;
    for(int i = 0; i < N; i++){
        scanf("%d %d",&tree.x,&tree.y);
        if(inTri(tree))
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
