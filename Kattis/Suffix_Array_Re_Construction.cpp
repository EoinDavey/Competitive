#include<bits/stdc++.h>
using namespace std;

int MX_LS = 10001;
int L,S;

char * in;
char * out;

bool check(int p){
    int i = 0;
    int n = strlen(in);
    int cnt = 0;
    for(i = 0; i < n; i++)
        if(in[i]!='*')
            cnt++;
    if(cnt > L-p)
        return false;
    i=0;
    while(i < n && in[i]!='*'){
        if(out[i+p] != '_' && out[i+p] != in[i])
            return false;
        out[i+p]=in[i];
        i++;
    }
    i = n-1;
    while(i >=0 && in[i] != '*'){
        if(out[L-(n-i)]!='_' && out[L-(n-i)]!=in[i])
            return false;
        out[L-(n-i)] = in[i];
        i--;
    }
    return true;
}

int main(){
    int T; scanf("%d",&T);
    out = new char[MX_LS];
    in = new char[MX_LS];
    while(~--T){
        scanf("%d %d",&L,&S);
        memset(out,'_',L);
        int p;
        bool fail = false;
        for(int i = 0; i < S; i++){
            scanf("%d %s",&p,in);
            fail |= !check(--p);
        }
        for(int i = 0; i < L && !fail; i++)
            if(out[i]=='_')
                fail=true;
        if(fail)
            puts("IMPOSSIBLE");
        else {
            out[L]='\0';
            puts(out);
        }
    }
    delete in;
    delete out;
    return 0;
}
