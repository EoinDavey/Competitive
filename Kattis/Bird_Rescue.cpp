#include<cstdio>

constexpr int MX_NQ = 100001, MX_D = 2000022;
int N,Q;
int f[MX_D];
int X,Y;

inline int read_int(){
    int o = 0; char c;
    while(1){
        c = getchar_unlocked();
        if(c>='0' && c <= '9')
            break;
    }
    do {
        o = 10*o + c - '0';
        c = getchar_unlocked();
    } while(c>='0' && c <= '9');
    return o;
}

inline int LSOne(int i){ return i&(-i); }

inline void update(int k, int v){
    for(; k < MX_D; k+=LSOne(k)){
        f[k] += v;
    }
}

inline int get(int k){
    int sm = 0;
    for(; k > 0; k-=LSOne(k)){
        sm += f[k];
    }
    return sm;
}

inline int abs(int x){
    return x < 0 ? -x : x;
}

inline void swap(int& a, int& b){
    int t = b;
    b = a;
    a = t;
}

inline int mind(int x1,int x2, int y1, int y2){
    int xc,yc;
    if(x1 <= X && X <= x2)
        xc = X;
    else if(X < x1)
        xc = x1;
    else
        xc = x2;
    if(y1 <= Y && Y <= y2)
        yc = Y;
    else if(Y < y1)
        yc = y1;
    else
        yc = y2;
    return abs(X-xc) + abs(Y-yc);
}

inline int maxd(int x1, int x2, int y1, int y2){
    int xc = (abs(x1-X) > abs(x2-X)) ? x1 : x2;
    int yc = (abs(y1-Y) > abs(y2-Y)) ? y1 : y2;
    return abs(X-xc) + abs(Y-yc);
}

int main(){
    N = read_int();
    Q = read_int();
    X = read_int();
    Y = read_int();
    int x1,y1,x2,y2;
    for(int i = 0; i < N; ++i){
        x1 = read_int();
        y1 = read_int();
        x2 = read_int();
        y2 = read_int();
        if(x2 < x1)
            swap(x2,x1);
        if(y2 < y1)
            swap(y2,y1);
        int mnd = mind(x1,x2,y1,y2);
        int mxd = maxd(x1,x2,y1,y2);
        update(mnd+1,1);
        update(mxd+2,-1);
    }
    for(int i = 0; i < Q;++i){
        x1 = read_int();
        printf("%d\n",get(x1+1));
    }
    return 0;
}
