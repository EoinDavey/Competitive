#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <cstdlib>
#define ma(x,y) ((x+y)%INF)
#define mm(x,y) ((x*y)%INF)
#define ms(x,y) ((((x-y)%INF)+INF)%INF)
using namespace std;
int n, a, b;
long long INF = 1000000000 + 7;
const int MX_N = 1000*1000 + 10;
int memo[MX_N][23][2];
int prefix[MX_N];

void genDp(){
    for(int cur = 0; cur < MX_N; ++cur)
        for(int ws = 0; ws < 21; ++ws)
            memo[cur][ws][0] = memo[cur][ws][1] = 1;

    for(int cur = 1; cur < MX_N; ++cur){
        for(int ws = 0; ws < 23; ++ws){
            for(int lst = 0; lst < 2; ++lst){
                long long win_amount = pow(2, ws);
                long long route1 = 0LL;
                if (cur - win_amount >= 0)
                    route1 = memo[cur - win_amount][ws + 1][0] % INF;
                long long route2 = 0LL;
                if (!lst) 
                    route2 = memo[cur][0][1] % INF;
                long long res = (route1 + route2) % INF;
                memo[cur][ws][lst] = res;
            }
        }
    }
}

int main() {
    cin >> n;
    genDp();
    for(int i = 0; i < MX_N; ++i){
        prefix[i] = memo[i][0][0] % INF;
        if(i)
            prefix[i] = ma(prefix[i], prefix[i-1]);
    }
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << ms(prefix[b],(a == 0 ? 0 : prefix[a-1])) << endl;
    }
}
