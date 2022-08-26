#include<bits/stdc++.h>
using namespace std;

constexpr int MX_RDS = 10001;

int R,C,F,N,B,T;

struct pos {
    int x, y;
};

struct ride {
    int r_number;
    pos start;
    pos finish;
    int beg_t, end_t;
    bool operator < (ride &p) const {
        if(end_t!=p.end_t)
            return end_t < p.end_t;
        return beg_t < p.beg_t;
    }
};

vector<ride> rides;

inline int dist(pos &a, pos &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

inline int latest_start(int f, int dis){
    return f - dis;
}

int main(){
    scanf("%d %d %d %d %d %d",&R,&C,&F,&N,&B,&T);
    int a,b,x,y,s,f;
    for(int i = 0; i < N; ++i){
        scanf("%d %d %d %d %d %d",&a,&b,&x,&y,&s,&f);
        ride r;
        r.r_number = i;
        r.start = {a,b};
        r.finish = {x,y};
        r.beg_t = s;
        r.end_t = latest_start(f,dist(r.start,r.finish));
        if(r.end_t >= r.beg_t)
            rides.push_back(r);
    }
    bool covered[rides.size()];
    memset(covered,0,sizeof(covered));
    sort(rides.begin(),rides.end());
    vector<pos> cars;
    cars.resize(F, {0,0});
    vector<int> out[F];
    for(int i = 0; i < F; ++i){
        int t = 0;
        for(int j = 0; j < rides.size(); ++j){
            if(covered[j])
                continue;
            int eta = t+dist(cars[i],rides[j].start);
            if(eta <= rides[j].end_t){
                covered[j] = true;
                out[i].push_back(rides[j].r_number);
                cars[i] = rides[j].finish;
                t = max(rides[j].beg_t, eta) + dist(rides[j].start,rides[j].finish);
            }
        }
    }
    for(int i = 0; i < F; ++i){
        printf("%lu ",out[i].size());
        for(auto &r : out[i])
            printf("%d ",r);
        putchar('\n');
    }
    return 0;
}
