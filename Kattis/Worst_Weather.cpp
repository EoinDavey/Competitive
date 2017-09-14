#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

constexpr int MX_N = 50005;
constexpr int MX_LG=17;
int y[MX_N];
int r[MX_N];
int N,M;
int mtable[MX_N][MX_LG];
int scount=0;
int sq[MX_N];

inline int rmq(int u, int v){
    if(u > v)
        return -2000000000;
    int k = (int) floor(log2((double) (v-u+1)));
    if(r[mtable[u][k]] > r[mtable[v-(1<<k) + 1][k]])
        return r[mtable[u][k]];
    return r[mtable[v-(1<<k) + 1][k]];
}

int read_int(){
    char c;
    int out = 0;
    bool neg=false;
    while(1){
        c = getchar_unlocked();
        if((c >='0' && c <= '9') || c =='-')
            break;
    }
    do {
        if(c=='-'){
            neg = true;
            c = getchar_unlocked();
            continue;
        }
        out = (out*10) + (c-48);
        c = getchar_unlocked();
    }while(c >= '0' && c <= '9');
    return (neg? -out : out);
}

int main(){
    while(true){
        scount=0;
        N = read_int();
        for(int i = 0; i < N; i++){
            y[i] = read_int();
            r[i] = read_int();
        }
        for(int i = 0; i < N; i++)
            mtable[i][0] = i;
        for(int j = 1; (1 << j) <= N; j++)
            for(int i = 0; i + (1<<j)-1 < N; ++i)
                if(r[mtable[i][j-1]] > r[mtable[i + (1 << (j-1))][j-1]])
                    mtable[i][j] = mtable[i][j-1];
                else
                    mtable[i][j] = mtable[i+(1<<(j-1))][j-1];
        if(N>0)
            sq[0]=0;
        for(int i = 1; i < N; i++)
            if(y[i] == y[i-1]+1)
                sq[i]=sq[i-1];
            else
                sq[i]=++scount;
        M = read_int();
        if(N==0 && M==0)
            break;
        int a,b;
        for(int i = 0; i < M; i++){
            a = read_int();
            b = read_int();
            int lp = lower_bound(y,y+N,a) - y;
            int rp = lower_bound(y,y+N,b) - y;
            if(rp==N || y[rp]>b)
                --rp;
            if(lp >= N || rp < 0){
                puts("maybe");
                continue;
            }
            bool tr = true;
            bool fls = false;
            if(y[lp]==a && y[rp]==b){
                if(sq[lp]!=sq[rp])
                    tr = false;
                if(r[lp] < r[rp])
                    fls = true,tr=false;
                int mx = rmq(lp+1,rp-1);
                if(mx >= r[rp])
                    fls=true,tr=false;
            } else {
                tr = false;
                if(y[lp]==a){
                    int mx = rmq(lp+1,rp);
                    if(mx >= r[lp])
                        fls = true;
                } else if(y[rp]==b){
                    int mx = rmq(lp,rp-1);
                    if(mx >= r[rp])
                        fls = true;
                }
            }
            if(tr){
                puts("true");
                continue;
            }
            if(fls){
                puts("false");
                continue;
            }
            puts("maybe");
        }
        putchar('\n');
    }
    return 0;
}
