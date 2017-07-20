#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N,L[20],R[20],memo[20][20];

int solve(int l, int r,int d){
    if(l==r)
        return memo[l][r] = 0;
    if(memo[l][r]!=-1)
        return memo[l][r];
    int mn = -1; bool mnb = false;
    for(int i = l; i < r; i++){
        int cost = solve(l,i,d+1) + solve(i+1,r,d+1) + L[l] * R[i] * R[r];
        if(cost<mn || !mnb)
            mn=cost,mnb=true;
    }
    return memo[l][r] = mn;
}

void print(int l, int r){
    if(l==r)
        printf("A%d",l+1);
    for(int i = l; i < r; i++){
        if(memo[l][i] + memo[i+1][r] + L[l]*R[i]*R[r] == memo[l][r]){
            if(i-l>0){
                putchar('(');
                print(l,i);
                putchar(')');
            } else
                print(l,i);
            printf(" x ");
            if(r-i>1){
                putchar('(');
                print(i+1,r);
                putchar(')');
            } else
                print(i+1,r);
            break;
        }
    }
}

int main(){
    int _t = 1;
    while(1){
        scanf("%d",&N);
        if(N==0)
            break;
        memset(memo,-1,sizeof(memo));
        for(int i = 0; i < N; i++)
            scanf("%d %d",&L[i],&R[i]);
        solve(0,N-1,0);
        printf("Case %d: ",_t++);
        putchar('(');
        print(0,N-1);
        printf(")\n");
    }
    return 0;
}
