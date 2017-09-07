#include<bits/stdc++.h>
using namespace std;

constexpr int MX_B =22;
constexpr int MX_N =101;
int B,N;
int v[MX_B];
bool f[MX_N][MX_B];

int read_int(){
    char c;
    int out=0;
    while(1){
        c = getchar_unlocked();
        if(c!=' '&&c!='\n')
            break;
    }
    do {
        out = out*10 + (c-'0');
        c = getchar_unlocked();
    } while(c!=' '&&c!='\n');
    return out;
}

int main(){
    B = read_int();
    for(int i = 0; i < B; i++)
        v[i] = read_int();
    N = read_int();
    for(int i = 0; i < N; i++){
        int M = read_int();
        while(~--M){
            f[i][read_int()-1]=true;
        }
    }
    int mx = 0;
    for(int i = 0; i < (1<<B); i++){
        bool valid = true;
        for(int j = 0; j < N && valid; j++){
            bool suc = false;
            for(int k = 0; k < B && !suc; k++){
                if(f[j][k] && (i&(1<<k))!=0)
                    suc = true;
            }
            if(!suc)
                valid = false;
        }
        if(valid){
            int cst = 0;
            for(int j = 0; j < B; j++){
                if((i&(1<<j))==0)
                    cst+=v[j];
            }
            mx = max(mx,cst);
        }
    }
    printf("%d\n",mx);
    return 0;
}
