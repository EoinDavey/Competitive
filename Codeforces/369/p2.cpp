#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int N;
long long int grid[501][501];
int x,y;

int main(){
    cin >> N;
    if(N==1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%l64d",&grid[i][j]);
            if(grid[i][j]==0)x=i,y=j;
        }
    }
    int r = 0;
    if(x==0)r++;
    long long int sum = 0;
    long long int s = 0;
    for(int i = 0; i < N;i++){
        sum+=grid[r][i];
    }
    for(int i = 0; i < N; i++){
        s+=grid[x][i];
    }
    long long int res = sum-s;
    bool f = false;
    grid[x][y]=res;
    for(int i = 0; i < N&&!f;i++){
        s=0;
        for(int j = 0; j < N&&!f;j++){
            s+=grid[i][j];
        }
        if(s!=sum)f=true;
    }
    for(int i = 0; i < N&&!f;i++){
        s=0;
        for(int j = 0; j < N&&!f;j++){
            s+=grid[j][i];
        }
        if(s!=sum)f=true;
    }
    s=0;
    for(int i = 0; i < N;i++){
        s+=grid[i][i];
    }
    if(s!=sum)f=true;
    s=0;
    for(int i = 0; i < N;i++){
        s+=grid[i][N-i-1];
    }
    if(s!=sum)f=true;
    if(!f&&res>0){
        cout << res << endl;
    }
    else cout << -1 << endl;
    return 0;
}
