#include<bits/stdc++.h>
using namespace std;

const int MX_NM=101;
char board[MX_NM][MX_NM];
bool vis[MX_NM][MX_NM];
int N,M;

vector<char> path;

bool valid(int i, int j){
    return i >= 0 && j >= 0 && i < N && j < M && board[i][j]!='*';
}

bool dfs(int i, int j){
    vis[i][j]=true;
    if(board[i][j] == 'F')
        return true;
    if(valid(i-1,j) && !vis[i-1][j] && dfs(i-1,j)){
        path.push_back('U');
        return true;
    }
    if(valid(i+1,j) && !vis[i+1][j] && dfs(i+1,j)){
        path.push_back('D');
        return true;
    }
    if(valid(i,j-1) && !vis[i][j-1] && dfs(i,j-1)){
        path.push_back('L');
        return true;
    }
    if(valid(i,j+1) && !vis[i][j+1] && dfs(i,j+1)){
        path.push_back('R');
        return true;
    }
    return false;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf(" %c",&board[i][j]);
    dfs(0,0);
    bool lrSwp,lrSlv,udSwp,udSlv;
    lrSlv=udSlv=false;
    int x,y;
    x=y=1;
    for(auto i = path.rbegin(); i != path.rend(); i++){
        int nx,ny;
        if(!udSlv && *i == 'D'){
            puts("D");
            fflush(stdout);
            scanf("%d %d",&nx,&ny);
            udSwp = nx==x&&ny==y;
            udSlv=true;
            if(udSwp){
                puts("U");
                fflush(stdout);
                scanf("%d %d",&nx,&ny);
            }
        } else if(!lrSlv && *i == 'R'){
            puts("R");
            fflush(stdout);
            scanf("%d %d",&nx,&ny);
            lrSwp = nx==x&&ny==y;
            lrSlv=true;
            if(lrSwp){
                puts("L");
                fflush(stdout);
                scanf("%d %d",&nx,&ny);
            }
        } else {
            if(lrSwp && (*i=='L' || *i=='R')){
                if(*i=='L')
                    puts("R");
                if(*i=='R')
                    puts("L");
            } else if(udSwp && (*i=='D' || *i=='U')){
                if(*i=='U')
                    puts("D");
                if(*i=='D')
                    puts("U");
            } else {
                printf("%c\n",*i);
            }
            fflush(stdout);
            scanf("%d %d",&nx,&ny);
        }
        x = nx; y = ny;
    }
    return 0;
}
