#include<cstdio>

constexpr int MX_RC = 1001;
int R,C,ni,nj,out,r1,c1,r2,c2,n,cCnt;
bool board[MX_RC][MX_RC];
int comp[MX_RC][MX_RC];
char c;

constexpr char ne[] = "neither";
constexpr char bi[] = "binary";
constexpr char dc[] = "decimal";
constexpr int moves[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void fill(int i, int j, int c){
    comp[i][j] = c;
    for(int k =0; k < 4; k++){
        ni = i+moves[k][0];
        nj = j+moves[k][1];
        if(ni >= 0 && nj >= 0 && ni < R && nj < C && board[i][j] == board[ni][nj] && comp[ni][nj]==0)
            fill(ni,nj,c);
    }
}

inline int read_int(){
    out = 0;
    while(1){
        c = getchar_unlocked();
        if(c!=' ' && c!='\n')
            break;
    }
    do {
        out = out*10 + (c-'0');
        c = getchar_unlocked();
    }while(c!=' ' && c != '\n');
    return out;
}

int main(){
    R = read_int();
    C = read_int();
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            do {
                c = getchar_unlocked();
            } while(c==' ' || c=='\n');
            board[i][j]= c=='1';
        }
    }
    cCnt = 1;
    n = read_int();
    for(int i = 0; i < n; ++i){
        r1 = read_int()-1;
        c1 = read_int()-1;
        r2 = read_int()-1;
        c2 = read_int()-1;
        if(comp[r1][c1] == 0)
            fill(r1,c1,++cCnt);
        if(comp[r1][c1]!=comp[r2][c2])
            puts(ne);
        else
            puts((board[r1][c1] ? dc : bi));
    }
    return 0;
}
