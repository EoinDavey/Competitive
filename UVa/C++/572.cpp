#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int N,M;
bool grid[101][101],visited[101][101];

bool valid(int x, int y){
    return grid[x][y]&&!visited[x][y];
}

void visit(int x, int y){
    if(x>0){
        if(valid(x-1,y)){
            visited[x-1][y]=true;
            visit(x-1,y);
        }
        if(y>0){
            if(valid(x-1,y-1)){
                visited[x-1][y-1] = true;
                visit(x-1,y-1);
            }
        }
        if(y<N-1){
            if(valid(x-1,y+1)){
                visited[x-1][y+1]=true;
                visit(x-1,y+1);
            }
        }
    }
    if(x<M-1){
        if(valid(x+1,y)){
            visited[x+1][y]=true;
            visit(x+1,y);
        }
        if(y>0){
            if(valid(x+1,y-1)){
                visited[x+1][y-1] = true;
                visit(x+1,y-1);
            }
        }
        if(y<N-1){
            if(valid(x+1,y+1)){
                visited[x+1][y+1]=true;
                visit(x+1,y+1);
            }
        }
    }
    if(y>0){
        if(valid(x,y-1)){
            visited[x][y-1] = true;
            visit(x,y-1);
        }
    }
    if(y<N-1){
        if(valid(x,y+1)){
            visited[x][y+1]=true;
            visit(x,y+1);
        }
    }
}

int main(){
    while(true){
        scanf("%d %d",&M,&N);
        if(M==0)break;
        memset(grid,0,sizeof(grid));
        memset(visited,0,sizeof(visited));
        char c;
        for(int i = 0; i < M; i++){
            for(int j = 0;j < N; j++){
                scanf("%c",&c);
                if(c=='\n'){
                    j--;
                    continue;
                }
                if(c=='*')grid[i][j]=false;
                else grid[i][j] = true;
            }
        } 
        int ct=0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N;j++){
                if(!visited[i][j]&&grid[i][j]){
                    ct ++;
                    visit(i,j);
                }
            }
        }
        cout << ct << endl;
    }
    return 0;
}
