#include<iostream>
#include<cstdio>

using namespace std;

int p[33333];
int rnk[33333];

void insert(int i){
    p[i]=i;
    rnk[i]=1;
}

int find(int i){
    if(p[i]==i)
        return i;
    return p[i] = find(p[i]);
}

void join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa==pb)
        return;
    if(rnk[pa] < rnk[pb]){
        int t = pa;
        pa = pb;
        pb = t;
    }
    p[pb]=pa;
    if(rnk[pa]==rnk[pb])
        rnk[pa]++;
}

int N,M;

int main(){
    while(1){
        scanf("%d %d",&N,&M);
        if(N==0&&M==0)
            break;
        for(int i = 0; i < N; i++)
            insert(i);
        for(int i = 0; i < M; i++){
            int k; scanf("%d",&k);
            int id; scanf("%d",&id);
            for(int j = 0; j < k-1; j++){
                int st; scanf("%d",&st);
                join(st,id);
            }
        }
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(find(i)==find(0))
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
