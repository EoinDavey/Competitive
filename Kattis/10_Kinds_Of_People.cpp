#include<cstdio>

constexpr int MX_RC = 1001;
int R,C,ni,nj,out,r1,c1,r2,c2,n,cCnt,pa,pb,i,j,k;
bool board[MX_RC][MX_RC];
char c;
int p[MX_RC*MX_RC];
int rank[MX_RC*MX_RC];

constexpr char ne[] = "neither";
constexpr char bi[] = "binary";
constexpr char dc[] = "decimal";

int find(int u){ return p[u] = (p[u] == u ? u : find(p[u])); }

inline void join(int a, int b){
    pa = find(a);
    pb = find(b);
    if(pa!=pb){
        if(rank[pa] < rank[pb]){
            ni = pb;
            pb = pa;
            pa = ni;
        }
        p[pb] = pa;
        if(rank[pa]==rank[pb])
            rank[pa]++;
    }
}

inline int ctol(int a, int b){
    return a*C + b;
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
    for(i = 0; i < R; ++i){
        for(j = 0; j < C; ++j){
            do {
                c = getchar_unlocked();
            } while(c==' ' || c=='\n');
            board[i][j]= c=='1';
            ni = ctol(i,j);
            p[ni] = ni;
            rank[ni] = 1;
        }
    }
    for(i = 0; i < R; ++i){
        for(j = 0; j < C; ++j){
            ni = i;
            nj = j - 1;
            if(ni >= 0 && nj >= 0 && board[i][j]==board[ni][nj])
                join(ctol(i,j),ctol(ni,nj));
            ni = i - 1;
            nj = j;
            if(ni >= 0 && nj >= 0 && board[i][j]==board[ni][nj])
                join(ctol(i,j),ctol(ni,nj));
        }
    }
    cCnt = 1;
    n = read_int();
    for(i = 0; i < n; ++i){
        r1 = read_int()-1;
        c1 = read_int()-1;
        r2 = read_int()-1;
        c2 = read_int()-1;
        if(board[r1][c1] != board[r2][c2] || find(ctol(r1,c1))!=find(ctol(r2,c2))){
            fputs_unlocked(ne,stdout);
            putchar_unlocked('\n');
        }else{
            fputs_unlocked((board[r1][c1] ? dc : bi),stdout);
            putchar_unlocked('\n');
        }
    }
    return 0;
}
