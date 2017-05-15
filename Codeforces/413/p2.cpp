#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

typedef long long ll;

using namespace std;

const int mx_n = 200002;
ll p[mx_n];
int N;

int main(){
    scanf("%d",&N);
    priority_queue<pair<ll,ll> , vector<pair<ll, ll> >, greater<pair<ll, ll> > > col[4];
    for(int i = 0; i < N; i++)
        scanf("%lld",&p[i]);
    ll a;
    for(int i = 0; i < N; i++){
        scanf("%lld",&a);
        col[a].push(make_pair(p[i],i));
    }
    for(int i = 0; i < N; i++){
        scanf("%lld",&a);
        col[a].push(make_pair(p[i],i));
    }
    int m; scanf("%d",&m);
    for(int i = 0; i < m; i++){
        scanf("%lld",&a);
        while(!col[a].empty() && p[col[a].top().second]==-1)
            col[a].pop();
        if(col[a].empty())
            printf("-1 ");
        else{
            printf("%lld ",p[col[a].top().second]);
            p[col[a].top().second]=-1;
            col[a].pop();
        }
    }
    printf("\n");
    return 0;
}
