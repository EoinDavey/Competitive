#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N,M,K;
int cnt = 0;
char board[51][51];
bool v[51][51];
int output = 0;

struct lake{
    int x,y,n;
    lake(int ix, int iy, int in){
        x=ix;
        y=iy;
        n=in;
    }
    bool operator < (const lake& rhs) const{
        return n<rhs.n;
    }
};

int visit(int x, int y, bool fill){
    if(x==0||x==N-1||y==0||y==N-1)return -1;
    v[x][y]=true; 
    int n;
    int c=1;
    if(x>0){
        if(board[x-1][y]=='.'&&!v[x-1][y]){
            n = visit(x-1,y,fill);
            if(n==-1) return -1;
            else c+=n;
        }
    }
    if(x<N-1){
        if(board[x+1][y]=='.'&&!v[x+1][y]){
            n=visit(x+1,y,fill);
            if(n==-1)return-1;
            else c+=n;
        }
    }
    if(y>0){
        if(board[x][y-1]=='.'&&!v[x][y-1]){
            n=visit(x,y-1,fill);
            if(n==-1)return-1;
            else c+=n;
        }
    }
    if(y<M-1){
        if(board[x][y+1]=='.'&&!v[x][y+1]){
            n=visit(x,y+1,fill);
            if(n==-1)return-1;
            else c+=n;
        }
    }
    if(fill)board[x][y]='*',output++;
    return c;
}

int main(){
    cin >> N >> M >> K;
    char c;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%c",&c);
            if(c=='\n'){
                j--;
                continue;
            }
            board[i][j]=c;
        }
    }
    vector<lake> lakes;
    for(int i = 0; i< N; i++){
        for(int j= 0; j < M; j++){
            if(!v[i][j]&&board[i][j]=='.'){
                int s = visit(i,j,false);
                if(s!=-1){
                    lakes.push_back(lake(i,j,s));
                }
            }
        }
    }
    sort(lakes.begin(),lakes.end());
    cnt=lakes.size();
    for(int i = 0; i < N; i++){
        memset(v[i],false,sizeof(v[i]));
    }
    for(int i = 0; i < cnt-K; i++){
        visit(lakes[i].x,lakes[i].y,true);
    }
    cout << output << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
