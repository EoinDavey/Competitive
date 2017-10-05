#include<cstdio>

constexpr int MX_N=1000001;
int N,M,in;
int a[MX_N];

inline int read_int(){
    char c;
    int out = 0;
    while(1){
        c = getchar_unlocked();
        if(c!=' '&&c!='\n')
            break;
    }
    do {
        out = out*10 + (c-'0');
        c = getchar_unlocked();
    }while(c!=' '&&c!='\n');
    return out;
}

int main(){
    while(true){
        N = read_int(); M = read_int();
        if(!N && !M)
            break;
        for(int i = 0; i < N; i++)
            a[i] = read_int();
        int ind = 0;
        int cnt = 0;
        for(int i = 0; i < M; ++i){
            int n = read_int();
            while(a[ind] < n && ind < N)
                ind++;
            if(a[ind]==n)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
