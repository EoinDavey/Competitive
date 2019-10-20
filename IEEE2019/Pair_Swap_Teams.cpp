#include<iostream>
#include<cstring>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) cin >> x >> y >> z
#define rd2(x,y) cin >> x >> y
#define rd(x) cin >> x
#define pr3(x,y,z) cout << x << ' ' << y << ' ' << z << endl
#define pr2(x,y) cout << x << ' ' << y << endl
#define pr(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << ' ' << endl
#ifdef JUDGE
#define dbg(x) x
#else
#define dbg(x)
#endif
#define msub(a,b,m) ((((a - b) % m) + m) % m)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

int edgeCnt[4][4];
int edgeCntCopy[4][4];
const int MX_N = 100010;
int v[MX_N], N, indmp[4];
bool vis[4];
int cnt[4];
bool st[4];
char s[MX_N];

int permcnt[] = {0,1,2,6,24};
int cyccnt[] = {0,0,1,5,20};
int cycles[][20][4] = {
    {
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
    },
    {
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3},
    },
    {
        {1,0,2,3},
        {0,1,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
        {1,0,2,3},
    },
    {
        {1,0,2,3},
        {0,2,1,3},
        {2,1,0,3},
        {1,2,0,3},
        {2,0,1,3},
        {0,1,2,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
        {2,0,1,3},
    },
    {
        {0,1,3,2},
        {0,2,1,3},
        {0,2,3,1},
        {0,3,1,2},
        {0,3,2,1},
        {1,0,2,3},
        {1,2,0,3},
        {1,2,3,0},
        {1,3,0,2},
        {1,3,2,0},
        {2,0,1,3},
        {2,0,3,1},
        {2,1,0,3},
        {2,1,3,0},
        {2,3,1,0},
        {3,0,1,2},
        {3,0,2,1},
        {3,1,0,2},
        {3,1,2,0},
        {3,2,0,1},
    }
};

inline int swpCount(int elcnt){
    memcpy(edgeCntCopy, edgeCnt, sizeof(edgeCnt));

    int tot = 0;
    for(int c = 0; c < cyccnt[elcnt]; ++c){
        for(int i = 0; i < elcnt; ++i){
            if(cycles[elcnt][c][i] == i)
                continue;
            int p = i;
            int ln = 0;
            int mn = edgeCntCopy[p][cycles[elcnt][c][p]];
            do {
                mn = min(mn, edgeCntCopy[p][cycles[elcnt][c][p]]);
                p = cycles[elcnt][c][p];
                ln += 1;
            } while(p != i);

            p = i;
            do {
                edgeCntCopy[p][cycles[elcnt][c][p]] -= mn;
                p = cycles[elcnt][c][p];
            } while(p != i);

            tot += (ln - 1) * mn;
            break;
        }
    }

    return tot;
}

inline int wrongPlace(){
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < N; ++i)
        cnt[v[i]]++;
    int elcnt = 1;
    for(int i = 0; i < N; ++i) 
        elcnt = max(elcnt, v[i]+1);

    memset(edgeCnt, 0, sizeof(edgeCnt));
    int indxs[elcnt];
    int lb = 0;
    for(int i = 0; i < elcnt; ++i){
        for(int j = 0; j < cnt[i]; ++j){
            if(v[lb] != i){
                ++edgeCnt[i][v[lb]];
            }
            lb = (lb + 1) % N;
        }
        indxs[i] = lb;
    }

    int mn = swpCount(elcnt);
    for(int _k = 0; _k < N; ++_k) {

        for(int j = 0; j < elcnt; ++j){
            int newval = v[indxs[j]];
            if(newval != j)
                ++edgeCnt[j][newval];
            int oldval = v[msub(indxs[j],cnt[j],N)];
            if(oldval != j)
                --edgeCnt[j][oldval];

            indxs[j] = (indxs[j]+1)%N;
        }

        mn = min(mn, swpCount(elcnt));
    }
    return mn;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T; rd(T);
    while(T -->0){
        rd(s);
        N = strlen(s);
        memset(st, 0, sizeof(st));
        int elcnt = 0;
        for(int i = 0; i < N; ++i)
            st[s[i]-'A'] = true;

        for(int i = 0; i < 4; ++i)
            elcnt += st[i];

        int cnt = 0;
        for(int i = 0; i < 4; ++i)
            if(st[i])
                indmp[i] = cnt++;

        int mn = INFI;
        for(int c = 0; c < permcnt[elcnt-1]; ++c){
            for(int i = 0; i < N; ++i)
                v[i] = cycles[elcnt-1][c][indmp[s[i]-'A']];
            mn = min(wrongPlace(), mn);
        }
        pr(mn);
    }
    return 0;
}
