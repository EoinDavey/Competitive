#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll moves[][2] = {{0,2018},{0,-2018},{2018,0},{-2018,0},{1680,1118},{-1680,1118},{1680,-1118},{-1680,-1118},{1118,1680},{-1118,1680},{1118,-1680},{-1118,-1680}};
const int K = 12;
const int MX_N = 100001;
int N;

int main(){
    scanf("%d",&N);
    set<ii> pts;
    ll x, y, nx,ny;
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        scanf("%lld %lld",&x,&y);
        ii p = {x,y};
        for(int k = 0; k < K; ++k){
            nx = x+moves[k][0];
            ny = y+moves[k][1];
            if(pts.count({nx,ny}) > 0)
                cnt++;
        }
        pts.insert(p);
    }
    printf("%d\n",cnt);
    return 0;
}
