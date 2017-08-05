#include<iostream>
#include<cstdio>
#define ii pair<int,int>

using namespace std;

int p[111];
ii stores[111];

int dist(int a, int b){
    ii ia = stores[a];
    ii ib = stores[b];
    return abs(ia.first-ib.first)+abs(ib.second-ia.second);
}

int find(int i){ return p[i] = p[i]==i ? i : find(p[i]);}

void join(int a, int b){
    int pa=find(a);
    int pb=find(b);
    if(pa!=pb)
        p[pa]=pb;
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        int N; scanf("%d",&N);
        int x,y;
        for(int i = 0; i < N+2; i++){
            scanf("%d %d",&x,&y);
            p[i]=i;
            stores[i].first=x;
            stores[i].second=y;
        }
        for(int i = 0; i < N+2; i++){
            for(int j = i+1; j < N+2; j++){
                if(dist(i,j) <= 1000){
                    join(i,j);
                }
            }
        }
        if(find(0)==find(N+1))
            puts("happy");
        else
            puts("sad");
    }
    return 0;
}
