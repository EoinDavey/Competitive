#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 100011;
constexpr int INF = 100000000;
int R,C,F,N,B,T;

struct pos {
    int x, y;
    bool operator == (const pos &p) const{
        return x==p.x && y==p.y;
    }
};

struct ride {
    int r_number;
    pos start;
    pos finish;
    int beg_t, end_t;
    int dist;
    bool operator == (const ride &p) const{
        return start==p.start && finish==p.finish && beg_t == p.beg_t && end_t == p.end_t;
    }
};

struct car {
    int t;
    pos cur;
    vector<int> path;
};

list<ride> rides;


inline int dist(const pos &a, const pos &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

inline int rideScore(const car &c, const ride &r){
    int arr_t = c.t + dist(c.cur,r.start);
    if(arr_t > r.end_t)
        return INF;
    bool bonus = arr_t <= r.beg_t;
    int trvl_t = dist(c.cur,r.start) + max(0,r.beg_t - arr_t) - bonus*2*B;
    return trvl_t;
}

inline bool compRides(const car &c, const ride &a, const ride &b){
    return rideScore(c,a) < rideScore(c,b);
}

inline ride bst_ride(const car &c){
    ride out = rides.front();
    for(auto r : rides)
        if(compRides(c,r,out))
            out = r;
    return out;
}

int main(){
    assert(scanf("%d %d %d %d %d %d",&R,&C,&F,&N,&B,&T)==6);
    int a,b,x,y,s,f;
    for(int i = 0; i < N; ++i){
        assert(scanf("%d %d %d %d %d %d",&a,&b,&x,&y,&s,&f)==6);
        ride r;
        r.r_number = i;
        r.start = {a,b};
        r.finish = {x,y};
        r.dist = dist(r.start,r.finish);
        r.beg_t = s;
        r.end_t = f-r.dist;
        if(r.end_t >= r.beg_t){
            rides.push_back(r);
        }
    }

    vector<car> cars; cars.resize(F,{0,{0,0}});

    bool survive = true;
    while(survive){
        survive=false;
        for(car &c : cars){
            ride r = bst_ride(c);
            int eta = c.t+dist(c.cur,r.start);
            if(eta> r.end_t)
                continue;
            survive=true;
            c.path.push_back(r.r_number);
            c.cur = r.finish;
            c.t = max(r.beg_t,eta) + r.dist;
            rides.remove(r);
        }
    }

    for(const auto &c : cars){
        printf("%lu ",c.path.size());
        for(auto r : c.path)
            printf("%d ",r);
        putchar('\n');
    }

    return 0;
}
