#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

char grid[110][110];
int delta[7][2] = {{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
string term;
int N,xe,ye;

bool search(int x, int y, int di,int dj, int pos){
    if(pos==term.length()){
        xe = x;
        ye = y;
        return true;
    }
    if(x+di < 0 || x+di >= N || y+dj < 0 || y+dj >= N) return false;
    if(grid[x+di][y+dj] == term[pos]) return search(x+di,y+dj,di,dj,pos+1);
    return false;
}

int main(){
    cin >> N;
    for(int i= 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf(" %c",&grid[i][j]);
    while(cin >> term){
        if(term=="0")
            break;
        bool found = false;
        int i,j;
        i = j = 0;
        for(i = 0; i < N && !found; i++)
            for(j = 0; j < N && !found; j++)
                for(int k = 0; k < 7 && !found; k++)
                    if(grid[i][j]==term[0])
                        found = search(i,j,delta[k][0],delta[k][1],1);
        if(!found)
            cout << "Not found\n";
        else printf("%d,%d %d,%d\n",i,j,xe+1,ye+1);
    }
    return 0;
}
