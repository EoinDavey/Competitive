#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

map<int, int> hMins[2];

int dist(int x1,int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main(){
    int n; scanf("%d",&n);
    int x,y;
    set<int> hghts;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &x, &y);
        int h = max(x,y);
        hghts.insert(h);
        if(hMins[0].find(h) != hMins[0].end()){
            hMins[0][h] = min(hMins[0][h], x);
        } else {
            hMins[0][h] = x;
        }
        if(hMins[1].find(h) != hMins[1].end()){
            hMins[1][h] = min(hMins[1][h], y);
        } else {
            hMins[1][h] = y;
        }
    }
    vector<int> heightV(hghts.begin(), hghts.end());
    sort(heightV.begin(), heightV.end());
    int dist1,dist2;dist1=dist2=0;
    ii prv[2] = {{0,0}, {0,0}};
    bool md = 0;
    puts("dists");
    for(int h : heightV) {
        printf("%d %d\n", dist1,dist2);
        dist1 += dist(prv[md].first, prv[md].second, md ? h : hMins[md][h], !md ? h : hMins[md][h]);
        dist2 += dist(prv[!md].first, prv[!md].second, !md ? h : hMins[!md][h], md ? h : hMins[!md][h]);
        prv[md].first = md ? h : hMins[md][h];
        prv[md].second = !md ? h : hMins[md][h];
        prv[!md].first = !md ? h : hMins[!md][h];
        prv[!md].second = md ? h : hMins[!md][h];
        int spanDist = dist(h,hMins[1][h], hMins[0][h], h);
        dist1+=spanDist;
        dist2+=spanDist;
        md = !md;
    }
    printf("%d\n", min(dist1,dist2));
    return 0;
}
