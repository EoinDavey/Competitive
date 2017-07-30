#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#define ii pair<int,int>

using namespace std;

const int MX_N = 1200;

ii all_points[1200];
int p[MX_N];
int rnk[MX_N];

int N,M,K,D;

int sq(int i){
    return i*i;
}

int dist(int a, int b){
    ii ta = all_points[a];
    ii tb = all_points[b];
    return sq(ta.first-tb.first) + sq(ta.second-tb.second);
}

void insert(int a){
    p[a]=a;
    rnk[a]=1;
}

int find_parent(int i){
    if(p[i]==i)
        return i;
    return p[i]=find_parent(p[i]);
}

void join(int a, int b){
    int pa = find_parent(a);
    int pb = find_parent(b);
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

bool check(int sz){
    for(int i = M; i < sz; i++){
        for(int j = i+1; j < sz; j++){
            if(dist(i,j) <= K){
                join(i,j);
            }
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = M; j < sz; j++){
            if(dist(i,j) <= D){
                join(i,j);
            }
        }
        if(find_parent(i)==find_parent(M))
            return true;
    }
    return false;
}

int main(){
    int _T; scanf("%d",&_T);
    for(int _t = 0; _t<_T; _t++){
        scanf("%d %d %d %d",&N,&M,&K,&D);
        D*=D; K*=K;
        int _x,_y;
        memset(p,0,sizeof(p));
        memset(rnk,0,sizeof(rnk));

        int i;
        for(i = 0; i < M; i++){
            scanf("%d %d",&all_points[i].first,&all_points[i].second);
            insert(i);
        }
        int _b;
        for(int k = 0; k < N; k++){
            scanf("%d",&_b);
            for(int j = 0; j <  _b; j++){
                scanf("%d %d",&all_points[i+j].first,&all_points[i+j].second);
                insert(i+j);
                join(i+j,i);
            }
            i+=_b;
        }
        if(check(i))
            puts("Tree can be saved :)");
        else
            puts("Tree can't be saved :(");
    }
    return 0;
}
