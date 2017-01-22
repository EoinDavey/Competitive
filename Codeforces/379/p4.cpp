#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

struct piece{
    long long int first;
    long long int second;
    char pce;
    piece(long long int f, long long int s, char p){
        first =f;
        second = s;
        pce = p;
    }
    piece(){
    }
};

long long int N,x0,y0; 
piece pos[600000];
long long int INF = 205000000000L;


bool check(){
    piece diag[2][2];
    piece hor[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            diag[i][j] = piece(INF,INF,'\n');
            hor[i][j] = piece(INF, INF, '\n');
        }
    }
    for(int i = 0; i < N; i++){
        //prlong long intf("%c %d %d",pos[i].pce, pos[i].first, pos[i].second);
        if(abs(pos[i].first-x0) == abs(pos[i].second-y0)){
            int k,l; k = l = 0;
            if(pos[i].first  < x0) k = 1;
            if(pos[i].second < y0) l = 1;
            //prlong long intf(" ; Diagonal %d %d",k,l);
            if(abs(pos[i].first - x0) < abs(diag[k][l].first - x0)) diag[k][l] = pos[i];//, prlong long intf(" ; Closest");
        }
        if(pos[i].first == x0 || pos[i].second == y0){
            int k,l; k = l = 0;
            if(pos[i].first <= x0) k = 1;
            if(pos[i].second <= y0) l = 1;
            //prlong long intf(" ; Horizontal %d %d",k,l);
            if(max(abs(pos[i].first-x0), abs(pos[i].second-y0)) < max(abs(hor[k][l].first-x0), abs(hor[k][l].second - y0))) hor[k][l] = pos[i];
        }
    }
    for(int i = 0; i< 2; i++){
        for(int j = 0; j < 2; j++){
            if(diag[i][j].first!=INF && (diag[i][j].pce == 'B' || diag[i][j].pce=='Q')) return true;
            if(hor[i][j].first!=INF && (hor[i][j].pce == 'R' || hor[i][j].pce=='Q')) return true;
        }
    }
    return false;
}

int main(){
    scanf("%lld",&N);
    scanf("%lld %lld",&x0,&y0);
    long long int tx,ty;
    char tc;
    for(int i = 0; i < N; i++){
        scanf(" %c %lld %lld",&tc,&tx,&ty);
        pos[i] = piece(tx,ty,tc);
    }
    if(check()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
