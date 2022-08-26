#include<bits/stdc++.h>
using namespace std;

constexpr int MX_RDS = 10001;

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
};

struct car {
    int id;
    int t;
    pos cur;
    vector<int> path;
};

vector<ride> rides;

inline int dist(const pos &a, const pos &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

inline int latest_start(int f, int dis){
    return f - dis;
}

inline void csort(const car &c){
    sort(rides.begin(), rides.end(),
            [=](const ride &a, const ride &b) -> bool {
                int arr_t_a = c.t + dist(c.cur,a.start);
                bool bonus_a = arr_t_a <= a.beg_t;
                int trvl_t_a = dist(c.cur,a.start) + max(0,a.beg_t - arr_t_a) - bonus_a*B;
                int arr_t_b = c.t + dist(c.cur,b.start);
                bool bonus_b = arr_t_b <= b.beg_t;
                int trvl_t_b = dist(c.cur,b.start) + max(0,b.beg_t - arr_t_b) - bonus_b*B;
                return trvl_t_a < trvl_t_b;
            }
    );
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
        r.end_t = latest_start(f,r.dist);
        if(r.end_t >= r.beg_t)
            rides.push_back(r);
    }

    bool covered[N]; memset(covered,0,sizeof(covered));

    vector<car> cars; cars.resize(F);

    for(int i = 0; i < F; ++i)
        cars[i] = {i,0,{0,0}};

    bool survive = true;
    while(survive){
        survive = false;
        for(auto &c : cars){
            int t = c.t;
            pos cur = c.cur;
            csort(c);
            for(const auto &r : rides){
                if(covered[r.r_number])
                    continue;
                int eta = t+dist(cur,r.start);
                if(eta <= r.end_t){
                    survive = true;
                    covered[r.r_number] = true;
                    c.path.push_back(r.r_number);
                    c.cur = r.finish;
                    c.t = max(r.beg_t, eta) + r.dist;
                    break;
                }
            }
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
