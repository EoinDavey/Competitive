#include<bits/stdc++.h>
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
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 1000; //TODO
int pws[MX_N][MX_N];
int sm[MX_N][MX_N];

int main(){
    int s; rd(s);
    for(int x = 1; x <= 300; ++x){
        for(int y = 1; y <= 300; ++y){
            int rckId = x+10;
            int pw = y*rckId;
            pw+=s;
            pw*=rckId;
            pw = (pw/100) % 10;
            pw -= 5;
            pws[x-1][y-1] = pw;
        }
    }
    int mx = -INFI;

    for(int i = 0; i < 300; ++i){
        for(int j = 0; j < 300; ++j){
            sm[i][j] = pws[i][j];
            if(i)
                sm[i][j] += sm[i-1][j];
            if(j)
                sm[i][j] += sm[i][j-1];
            if(i && j)
                sm[i][j] -= sm[i-1][j-1];
        }
    }

    for(int bx  = 0; bx < 300; ++bx){
        for(int by  = 0; by < 300; ++by){
            for(int sz = 1; sz <= 300; ++sz){
                int tx = bx+sz-1;
                int ty = by+sz-1;
                if(tx < 0 || ty<0 || tx >= 300 || ty >= 300)
                    break;
                assert(tx >= 0 && tx < 300 && ty>=0 && ty < 300);
                int val = sm[tx][ty];
                if(bx)
                    val -= sm[bx-1][ty];
                if(by)
                    val -= sm[tx][by-1];
                if(bx&&by)
                    val += sm[bx-1][by-1];
                if(val > mx){
                    mx = val;
                    pr(bx+1 << ',' << by+1 << ',' << tx-bx+1);
                }
            }
        }
    }
    pr(mx);
    return 0;
}
