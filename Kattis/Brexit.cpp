#include<cstdio>
#include<queue>
const int MX_N = 200002;
std::vector<int> adjList[MX_N];
int nCount[MX_N];
bool out[MX_N];
int C,P,X,L,o,a,b,u,v;
char c;

inline int read_int(){
    o = 0;
    while(1){
        c = getchar_unlocked();
        if(c >= '0' && c <= '9')
            break;
    }
    while(c >= '0' && c <= '9'){
        o = 10*o + c-'0';
        c = getchar_unlocked();
    }
    return o;
}

int main(){
    C = read_int();P = read_int(); X = read_int(); L = read_int();
    for(int i = 0; i < P; ++i){
        a = read_int(); b = read_int();
        adjList[a].push_back(b);
        ++nCount[a];
        adjList[b].push_back(a);
        ++nCount[b];
    }
    std::queue<int> q;
    q.push(L);
    while(!q.empty()){
        u = q.front();q.pop();
        if(out[u])
            continue;
        out[u] = true;
        for(int i = 0; i < adjList[u].size(); ++i){
            v = adjList[u][i];
            if(out[v])
                continue;
            --nCount[v];
            if(nCount[v]*2 <= adjList[v].size()){
                if(v==X){
                    puts("leave");
                    return 0;
                }
                q.push(v);
            }
        }
    }
    if(out[X])
        puts("leave");
    else
        puts("stay");
    return 0;
}
