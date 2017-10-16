#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,int> grd;

constexpr int MX_G = 100001;
constexpr int MX_M = 20001;
int G,M;
multiset<int> xs[10001];

inline ll ctol(int i, int j){
    return ((ll)i)*10001LL + ((ll)j);
}

inline int read_int(){
    char c;
    int o = 0;
    while(1){
        c = getchar_unlocked();
        if(c >= '0' && c <= '9')
            break;
    }
    do {
        o = 10 * o + c - '0';
        c = getchar_unlocked();
    }while(c >= '0' && c <='9');
    return o;
}

int main(){
    G = read_int();
    int x,y,r;
    unordered_map<ll,int>::iterator c;
    for(int i = 0; i < G; ++i){
        x = read_int();
        y = read_int();
        xs[x].insert(y);
    }
    M = read_int();
    for(int i = 0; i < M; ++i){
        x = read_int();
        y = read_int();
        r = read_int();
        for(int j = max(0,x-r); j <= min(10000,x+r); ++j){
            int l = floor(sqrt(r*r-(x-j)*(x-j)));
            auto lb = xs[j].lower_bound(y-l);
            auto rb = xs[j].upper_bound(y+l);
            xs[j].erase(lb,rb);
        }
    }
    int tot=0;
    for(int i = 0; i <= 10000; ++i)
        tot+=xs[i].size();
    printf("%d\n",tot);
    return 0;
}
