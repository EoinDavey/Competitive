#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

string a,b;
int memo[90][90];
int prCount = 0;

int dp(int i, int j, int depth){
    if(i==0&&j==0){
        return memo[i][j] = 0;
    }
    if(memo[i][j]!=-1)
        return memo[i][j];
    int replace,del,ins,m;
    if(i>0 && j>0)replace = dp(i-1,j-1,depth+1) + ((a[i-1]==b[j-1])?0:1);
    if(i>0) m = del = 1 + dp(i-1, j,depth+1);
    if(j>0) m = ins = 1 + dp(i, j-1,depth+1);
    if(i>0&&j>0)m = min(replace, min(del,ins));
    return memo[i][j] = m;
}

void printDp(int i, int j){
    if(i==0&&j==0)
        return;
    if(i > 0 && j > 0 && memo[i][j] == memo[i-1][j-1] + ((a[i-1]==b[j-1])?0:1)){
        if(a[i-1]!=b[j-1])
            printf("%d Replace %d,%c\n",++prCount,i,b[j-1]);
        printDp(i-1,j-1);
    } else if(i > 0 && memo[i][j] == 1 + memo[i-1][j]){
        printf("%d Delete %d\n",++prCount,i);
        printDp(i-1,j);
    } else if(j > 0 && memo[i][j] == 1 + memo[i][j-1]){
        printf("%d Insert %d,%c\n",++prCount,i+1,b[j-1]);
        printDp(i,j-1);
    }
}

int main(){
    bool g= false;
    while(getline(cin,a)){
        getline(cin,b);
        if(g)cout << endl;
        g = true;
        memset(memo,-1,sizeof(memo));
        prCount = 0;
        cout << dp(a.length(),b.length(), 0) << endl;
        printDp(a.length(),b.length());
    }
    return 0;
}
