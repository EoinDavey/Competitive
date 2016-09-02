#include<iostream>
#include<vector>

using namespace std;

long long ans,n,m,k,w,e,dp[50005][505];

bool mark[50005];

vector<int>adj[50005];

void dfs(int v) {
  mark[v]=1;
  dp[v][0]=1;
  for(int i=0;i<adj[v].size();i++){
    int ch=adj[v][i];
    if(mark[ch])
      continue;
    dfs(ch);
    for(int j=0;j<k;j++)
      ans+=dp[v][k-j-1]*dp[ch][j];
    for(int j=0;j<k;j++)
      dp[v][j+1]+=dp[ch][j];
  }
}

int main() {
  cin>>n>>k;
  for(int i=0;i<n-1;i++) {
    cin>>e>>w;
    adj[w].push_back(e);
    adj[e].push_back(w);
  }
  dfs(1);
  cout<<ans<<endl;
}