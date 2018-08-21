#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MX_N = 155;
constexpr ll INF = 1000*1000*1000;

int N,M,Q;
ll dist[MX_N][MX_N];
bool has_cyc[MX_N];
bool reach[MX_N][MX_N];

void solve(int s, int t) {
  for(int i = 0; i < N; ++i){
    if(reach[s][i] && reach[i][t] && has_cyc[i]){
      puts("-Infinity");
      return;
    }
  }

  if(!reach[s][t]){
    puts("Impossible");
    return;
  }

  printf("%lld\n",dist[s][t]);
}

int main() {
  while(scanf("%d %d %d", &N, &M, &Q), N | M | Q) {

    memset(dist, 0, sizeof(dist));
    memset(has_cyc, 0, sizeof(has_cyc));
    memset(reach, 0, sizeof(reach));

    for(int i = 0; i < N; ++i){
      dist[i][i] = 0LL;
      reach[i][i] = true;
      for(int j = 0; j < i; ++j)
        dist[i][j] = dist[j][i] = INF;
    }

    int u,v; ll w;
    for(int i = 0; i < M; ++i){
      scanf("%d %d %lld", &u, &v, &w);
      dist[u][v] = min(dist[u][v], w);
      reach[u][v] = true;
    }

    for(int k = 0; k < N; ++k){
      for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
          if(dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] < INF && dist[k][j] < INF)
            dist[i][j] = dist[i][k] + dist[k][j];
          reach[i][j] |= reach[i][k] && reach[k][j];
        }
      }
    }

    for(int i = 0; i < N; ++i)
      if(dist[i][i] < 0LL)
        has_cyc[i] = true;

    for(int i = 0; i < Q; ++i){
      scanf("%d %d", &u, &v);
      solve(u,v);
    }
    putchar('\n');
  }
}
