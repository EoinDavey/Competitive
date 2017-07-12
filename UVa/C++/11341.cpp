#include<cmath>
#include<cstdio>
#include<iomanip>

using namespace std;

int T,N,M,L[111][111];
int memo[111][111];

int solve(int k, int w){
    if(k >= N)
        return 0;
    if(memo[k][w]!=-1)
        return memo[k][w];
    int ans = -1;
    for(int i = 1; i <= w; i++){
        if(L[k][i-1]<5)
            continue;
        int t = solve(k+1,w-i);
        if(t!=-1)
            t+=L[k][i-1];
        if(t>ans)
            ans = t;
    }
    return memo[k][w] = ans;
}

int main(){
    scanf("%d",&T);
    for(int _t=0; _t < T; _t++){
        scanf("%d %d",&N,&M);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf("%d",&L[i][j]);
            }
        }
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= M; j++){
                memo[i][j]=-1;
            }
        }
        int t = solve(0,M);
        // Fuck this nonsense, apparently 5.125 prints as 5.13....
        double avg = ((double)t)/((double)N);
        avg*=1000;
        avg=floor(avg);
        if(((int)avg)%10 == 5)
            avg+=1;
        avg/=1000.0;
        if(t!=-1)
            printf("Maximal possible average mark - %.2lf.\n",avg);
        else printf("Peter, you shouldn't have played billiard that much.\n");
    }
    return 0;
}
