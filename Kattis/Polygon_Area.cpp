#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point{
    int x, y;
    point(int _x, int _y):x(_x),y(_y){}
    point(){}
    point operator + (const point &p){
        return point(x+p.x,y+p.y);
    }
    point operator - (const point &p){
        return point(x-p.x,y-p.y);
    }
};

int cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}

int main(){
    while(1){
        int N;scanf("%d",&N);
        if(N==0)
            break;
        point poly[N];
        for(int i = 0; i < N; i++)
            scanf("%d %d",&poly[i].x,&poly[i].y);
        ll area = 0;
        bool ccwB=false;
        for(int i = 0; i < N; i++){
            area+=((ll)cross(poly[i],poly[(i+1)%N]));
        }
        if(area > 0)
            printf("CCW %.1lf\n",area/2.0);
        else
            printf("CW %.1lf\n",area/-2.0);
    }
    return 0;
}
