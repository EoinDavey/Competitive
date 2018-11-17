#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MX_N = 5005;
int N,K,X;
ll a[MX_N], memo[MX_N][MX_N];
const ll INF = 1000LL*1000LL*1000LL * 100LL * 100LL;

int main(){
    memset(memo, -1, sizeof(memo));
    scanf("%d %d %d", &N, &K, &X);
    for(int i = 0; i < N; ++i)
        scanf("%lld", a+i);

    for(int p = 0; p <= N; ++p)
        memo[p][0] = p < K ? 0 : -INF;

    for(int k = 1; k <= X; ++k){
        deque<int> q;
        for(int p = 0; p <= N; ++p){
            memo[p][k] = -INF;
            while(!q.empty() && q.front() < p-K)
                q.pop_front();
            if(!q.empty())
                memo[p][k] = max(memo[p][k], memo[q.front()][k-1] + a[q.front()]);
            while(!q.empty() && memo[q.back()][k-1] + a[q.back()] < memo[p][k-1] + a[p])
                q.pop_back();
            q.push_back(p);
        }
    }

    if(memo[N][X] < 0)
        puts("-1");
    else
        printf("%lld\n", memo[N][X]);

    return 0;
}
