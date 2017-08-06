#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ii pair<int,int>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
    return pow(x1-x2,2) + pow(y1-y2,2);
}

int main(){
    double L,W;
    int N,R; scanf("%lf %lf %d %d",&L,&W,&N,&R);
    R*=R;
    double centers[][2] = {{-L/2.0,0}, {L/2.0,0},{0,-W/2.0},{0,W/2.0}};
    bool reach[16];
    memset(reach,false,sizeof(reach));
    double x,y;
    for(int i = 0; i < N; i++){
        scanf("%lf %lf",&x,&y);
        int out = 0;
        for(int j = 0; j < 4; j++){
            if(dist(x,y,centers[j][0],centers[j][1]) <= R)
                out|=(1<<j);
        }
        reach[out]=true;
    }
    int mx = 5;
    for(int i = 0; i < (1<<16); i++){
        int cnt=0;
        int state=0;
        for(int j = 0; j < 16; j++){
            if(!reach[j] || (i&(1<<j))==0)
                continue;
            cnt++;
            state|=j;
        }
        if(state==15){
            mx=min(mx,cnt);
        }
    }
    if(mx==5)
        puts("Impossible");
    else
        printf("%d\n",mx);
    return 0;
}
