#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef pair<int,int> ii;

const int MX_N = 555;
int N, T;
int a[MX_N];
int memo[MX_N][5050];
bool first[MX_N];

int dfs(int k, int w){
    if(memo[k][w]!=-1)
        return memo[k][w];
    if(k >= N)
        return memo[k][w] = 0;
    int mx = dfs(k+1,w);
    if(w >= a[k])
        mx = max(mx,a[k]+dfs(k+1,w-a[k]));
    return memo[k][w] = mx;
}

void print(int k, int w){
    if(k>=N)
        return;
    if(k < N-1 && memo[k][w] == memo[k+1][w])
        print(k+1,w);
    else {
        first[k]=true;
        print(k+1,w-a[k]);
    }
}

int main(){
    scanf("%d %d",&T,&N);
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    memset(memo,-1,sizeof(memo));
    memset(first,0,sizeof(first));
    dfs(0,T);
    print(0,T);
    int t1,t2;
    t1=t2=0;
    for(int i = 0; i < N; i++)
        if(first[i])
            printf("%d ",t1),t1+=a[i];
        else
            printf("%d ",t2),t2+=a[i];
    putchar('\n');
    return 0;
}
