#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> cc;
typedef vector<int> vi;
const int MX_RC = 2002;
char board[MX_RC][MX_RC];
int R,C;

int p[MX_RC*MX_RC];
int sz[MX_RC*MX_RC];

int toFind(int i,int j){ return i *C + j;}
int find(int i) { return p[i]==i ? i : find(p[i]);}
void join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa==pb)
        return;
    p[pa]=pb;
    sz[pb]+=sz[pa];
}

int main(){
    scanf("%d %d",&R,&C);
    for(int i = 0; i < R; ++i)for(int j = 0; j < C; ++j)scanf(" %c",&board[i][j]);
    int s = 0;
    for(int i = 0; i < R; ++i)for(int j = 0; j < C; ++j){
        int k = toFind(i,j);
        p[k]= k;
        sz[k]=1;
    }
    for(int i = 0; i < R; ++i){
        int pv = -1;
        for(int j = 0; j < C; ++j){
            if(board[i][j]=='x'){
                if(pv!=-1)
                    join(toFind(i,j),pv);
                pv = toFind(i,j);
            }
        }
    }
    for(int j = 0; j < C; ++j){
        int pv = -1;
        for(int i = 0; i < R; ++i){
            if(board[i][j]=='x'){
                if(pv!=-1)
                    join(toFind(i,j),pv);
                pv = toFind(i,j);
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j){
            int k = toFind(i,j);
            if(p[k]==k)
                sum+=sz[k]-1;
        }
    printf("%d\n",sum);
    return 0;
}
