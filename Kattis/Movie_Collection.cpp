#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MX_N = 222222;
const int MID_N = MX_N/2;

int tree[MX_N];
int N,R;

int lsOne(int i){
    return i&(-i);
}

void update(int k,int v){
    for(; k<MX_N; k+=lsOne(k))
        tree[k]+=v;
}

int query(int k){
    int cnt=0;
    for(; k; k-=lsOne(k)){
        cnt+=tree[k];
    }
    return cnt;
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&R);
        int pos[N+3];
        memset(tree,0,sizeof(tree));
        for(int i = 1; i <= N; i++){
            update(MID_N+i,1);
            pos[i]=MID_N+i;
        }
        int idx = MID_N-1;
        int a;
        for(int i = 0; i < R; i++){
            scanf("%d",&a);
            int k = pos[a];
            if(i==0)
                printf("%d",query(k)-1);
            else 
                printf(" %d",query(k)-1);
            update(k,-1);
            pos[a]=idx;
            update(idx,1);
            idx--;
        }
        putchar('\n');
    }
    return 0;
}
