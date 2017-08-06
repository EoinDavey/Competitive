#include<iostream>
#include<cstdio>

using namespace std;

const int MX_N = 100011;
int p[2*MX_N+10];
int sz[2*MX_N+10];
long long sm[2*MX_N];

int find(int i){
    if(p[i]==i)
        return i;
    return p[i] = find(p[i]);
}

void join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa!=pb){
        p[pa]=pb;
        sz[pb]+=sz[pa];
        sm[pb]+=sm[pa];
    }
}

void swap(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa!=pb){
        p[b] = pa;
        sz[pb]--;
        sz[pa]++;
        sm[pa]+=b;
        sm[pb]-=b;
    }
}

int main(){
    int N,M;
    while(scanf("%d %d",&N,&M)==2){
        for(int i = 1; i <= N; i++)
            p[i]=MX_N+i,sm[MX_N+i]=i;
        for(int i = MX_N+1; i <= MX_N*2+5; i++)
            p[i]=i,sz[i]=1;
        int com,p,q;
        for(int i = 0; i < M; i++){
            scanf("%d",&com);
            switch(com){
                case 1:
                    scanf("%d %d",&p,&q);
                    join(p,q);
                    break;
                case 2:
                    scanf("%d %d",&p,&q);
                    swap(q,p);
                    break;
                case 3:
                    scanf("%d",&p);
                    int pp = find(p);
                    printf("%d %lld\n",sz[pp],sm[pp]);
                    break;
            }
        }
    }
    return 0;
}
