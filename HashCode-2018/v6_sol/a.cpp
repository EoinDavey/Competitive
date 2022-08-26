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
    bool operator < (const ride &p) const {
        if(end_t!=p.end_t)
            return end_t < p.end_t;
        return beg_t < p.beg_t;
    }
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
    int trvl_t = dist(c.cur,r.start) + max(0,r.beg_t - arr_t) - bonus*B;
    return trvl_t;
}

inline bool compRides(const car &c, const ride &a, const ride &b){
    return rideScore(c,a) < rideScore(c,b);
}

ride bst_ride(const car &c){
    ride out = rides.front();
    bool fnd = false;
    for(auto r : rides){
        if(!fnd || compRides(c,r,out))
            out = r,fnd=true;
    }
    return out;
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
        r.dist = dist(r.start,r.finish);
        r.beg_t = s;
        r.end_t = f-r.dist;
        if(r.end_t >= r.beg_t)
            rides.push_back(r);
    }

    vector<car> cars; cars.resize(F,{0,{0,0}});

    bool survive = true;
    while(survive && !rides.empty()){
        survive = false;
        int mx_sc = INF;
        int mx_c = 0;
        for(int i = 0; i < cars.size(); ++i){
            const car &c = cars[i];
            int r = rideScore(c,bst_ride(c));
            if(r < mx_sc){
                mx_sc = r;
                mx_c = i;
            }
        }

        car &c = cars[mx_c];
        ride r = bst_ride(c);
        int eta = c.t+dist(c.cur,r.start);
        if(eta <= r.end_t){
            survive = true;
            c.path.push_back(r.r_number);
            c.cur = r.finish;
            c.t = max(r.beg_t, eta) + r.dist;
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
