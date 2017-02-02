#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N,M;
int grid[1000][1000];


int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf(" %d",&grid[i][j]);
    int s = 0; bool b = false;
    for(int i = 0; i < N; i++){
        b = false;
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 1) b = true;
            if(grid[i][j]==0&&b==true) s++;
        }
    }
    for(int i = 0; i < N; i++){
        b = false;
        for(int j = M-1; j >=0; j--){
            if(grid[i][j] == 1) b = true;
            if(grid[i][j]==0&&b==true) s++;
        }
    }
    for(int i = 0; i < M; i++){
        b = false;
        for(int j = N-1; j >=0; j--){
            if(grid[j][i] == 1) b = true;
            if(grid[j][i]==0&&b==true) s++;
        }
    }
    for(int i = 0; i < M; i++){
        b = false;
        for(int j = 0; j < N; j++){
            if(grid[j][i] == 1) b = true;
            if(grid[j][i]==0&&b==true) s++;
        }
    }
    cout << s << endl;
    return 0;
}
