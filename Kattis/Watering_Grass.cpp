#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#define ii pair<double,double>

using namespace std;

int main(){
    double N,L,W;
    while(scanf("%lf %lf %lf",&N,&L,&W)==3){
        double _x,_r;
        vector<ii> v;
        for(int i = 0; i < N; i++){
            scanf("%lf %lf",&_x,&_r);
            if(_r*_r < (W/2.0)*(W/2.0))
                continue;
            double dx = sqrt(_r*_r - (W/2.0)*(W/2.0));
            v.push_back(make_pair(_x-dx,_x+dx));
        }
        sort(v.begin(),v.end());
        int cnt = 0;
        double l = 0;
        int i = 0;
        while(l < L){
            double newR=l;
            for(; i < v.size(); i++){
                if(v[i].first > l)
                    break;
                if(v[i].second>newR)
                    newR = v[i].second;
            }
            if(newR==l)
                break;
            l = newR;
            cnt++;
        }
        if(l >= L)
            printf("%d\n",cnt);
        else
            puts("-1");
    }
    return 0;
}
