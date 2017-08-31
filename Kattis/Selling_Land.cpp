#include<bits/stdc++.h>
using namespace std;

const int MX_RC=1000;
int R,C;
char board[MX_RC][MX_RC];
int h[MX_RC][MX_RC];
int p[MX_RC][MX_RC];

int perim(int l, int w){
    if(l==0 || w==0)
        return 0;
    return 2*l + 2*w;
}

int main(){
    scanf("%d %d",&R,&C);
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            scanf(" %c",&board[i][j]);
    for(int j = 0; j < C; j++){
        int run=0;
        for(int i = 0; i < R; i++){
            run = (board[i][j] == '.' ? run+1:0);
            h[i][j] = run;
        }
    }
    for(int i = 0; i < R; i++){
        vector<int> v;
        for(int j = 0; j < C; j++){
            if(v.empty() || h[i][j] > h[i][v.back()])
                v.push_back(j);
            for(auto k = v.begin(); k != v.end(); k++){
                p[i][j] = max(p[i][j],perim(h[i][*k], j - *k + 1));
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++)
            printf("%d ",p[i][j]);
        putchar('\n');
    }
    return 0;
}
