#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int N;
bool at[99][99];
bool proc[50][50];
char board[50][50];

int main(){
    cin >> N;
    char in;
    vector<pair<int, int> > pieces;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%c",&in);
            if(in=='\n')j--;
            else board[i][j]=in;
            if(in=='o') pieces.push_back(make_pair(i,j));
        }
    }
    int x,y,dx,dy,nx,ny;
    for(int p = 0; p < pieces.size(); p++){
        x = pieces[p].first;
        y = pieces[p].second;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dx = i-x;
                dy = j-y;
                bool a;
                bool b = false;
                if(board[i][j]=='.')a=false;
                else if(board[i][j]=='x')a=true;
                else continue;
                for(int k = 0; k < pieces.size()&&!b; k++){
                    nx=pieces[k].first+dx;
                    ny=pieces[k].second+dy;
                    if(nx>=0&&nx<N&&ny>=0&&ny<N){
                        if(board[nx][ny]=='.'&&a)b=true;
                        else if(board[nx][ny]=='x'&&!a)b=true;
                    }
                }
                if(!b)at[N-1+dx][N-1+dy]=a,proc[i][j]=true;
            }
        }
    }
    bool v = false;
    for(int i = 0; i < N&&!v; i++){
        for(int j = 0; j < N&&!v;j++){
            if(!proc[i][j]&&board[i][j]!='o'){
                printf("i:%d, j:%d\n",i,j);
                v=true;
            }
        }
    }
    for(int p = 0; p < pieces.size()&&!v; p++){
        x = pieces[p].first;
        y = pieces[p].second;
        for(int i = 0; i < 2*N - 1&&!v; i++){
            for(int j = 0; j < 2*N - 1&&!v; j++){
                dx = i-(N-1);
                dy = j-(N-1);
                nx = x+dx;
                ny = y+dy;
                if(nx>=0&&nx<N&&ny>=0&&ny<N){
                    if(board[nx][ny]=='.'&&at[i][j])v=true;
                }
                //if(v)printf("Piece:%d,i:%d,j:%d,nx:%d,ny%d,x:%d,y:%d,dx:%d,dy:%d\n",p,i,j,nx,ny,x,y,dx,dy);
            }
        }
    }
    if(v)cout << "NO" << endl;
    else{
        for(int i = 0; i < 2*N -1; i++){
            for(int j = 0; j < 2*N - 1; j++){
                if(!at[i][j])cout<<".";
                else cout << "x";
            }
            cout << endl;
        }
    }
    return 0;
}
