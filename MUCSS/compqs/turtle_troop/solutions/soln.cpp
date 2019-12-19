#include<cstdio>
constexpr int MX_N = 1001;
int ns[MX_N];

// Linear time solution (quick-select)

// Fast integer read
inline int read_int(){
    int sm = 0;
    int ml = 1;

    char c = getchar_unlocked();
    while(!('0' <= c && c <= '9')){
        if(c == '-')
            ml = -1;
        c = getchar_unlocked();
    }
    do {
        sm = 10*sm + c - '0';
        c = getchar_unlocked();
    } while('0' <= c && c <= '9');
    return sm*ml;
}

// quick select
void qs(int L, int R, int M){
    if(L >= R)
        return;
    int pi = L;
    int si = pi + 1;
    for(int i = L+1; i <= R; ++i){
        if(ns[i] > ns[pi]){
            int t = ns[i];
            ns[i] = ns[si];
            ns[si] = t;
            ++si;
        }
    }
    int t = ns[pi];
    ns[pi] = ns[si-1];
    ns[si-1] = t;

    // p is in position si - 1, si sorted
    if(si == M)
        return;
    if(si > M){
        qs(L, si-2, M);
        return;
    }
    qs(si, R, M);
}

int main(){
    int N, M;
    N = read_int();
    M = read_int();
    for(int i = 0; i < N; ++i)
        ns[i] = read_int();
    qs(0, N - 1, M);
    int sm = 0;
    for(int i = 0; i < M; ++i)
        sm += ns[i];
    printf("%d\n", sm);
    return 0;
}
