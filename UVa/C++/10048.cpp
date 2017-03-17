#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct edge{
    int a,b,w;
    edge(int _a, int _b, int _w) : a(_a), b(_b), w(_w){}
    edge(){}
    bool operator < (edge rhs) const {
        if(w != rhs.w) return w < rhs.w;
        if(a != rhs.a) return a < rhs.a;
        return b < rhs.b;
    }
};

int C,S,Q;
int p[111];
int r[111];
int mDis[111][111];
int INF = 100000;

int set(int a){
    if(p[a] == a) return a;
    return set(p[a]);
}

bool sameSet(int a, int b){
    return set(a) == set(b);
}

void joinSet(int a, int b){
    int x = set(a);
    int y = set(b);
    if(r[x] > r[y])
        p[y] = x;
    else {
        p[x] = y;
        if(r[x]==r[y])r[y]++;
    }
}

int main(){
    int count = 0;
    while(true){
        cin >> C >> S >> Q;
        if(C==0&&S==0&&Q==0)
            break;
        int ia, ib, iw;
        vector<edge> elist;
        for(int i = 1; i <=C; i++)
            for(int j = 1; j <= C; j++)
                mDis[i][j] = INF;
        for(int i = 0; i < S; i++){
            scanf("%d %d %d",&ia,&ib,&iw);
            elist.push_back(edge(ia,ib,iw));
        }
        for(int i =0; i <= C; i++)
            p[i] = i, r[i]=mDis[i][i]=0;
        sort(elist.begin(), elist.end());
        int tbDis[C+1];
        int taDis[C+1];
        for(int i = 0; i < S; i++){
            edge e = elist[i];
            if(!sameSet(e.a,e.b)){
                joinSet(e.a,e.b);
                mDis[e.a][e.b] = mDis[e.b][e.a] = e.w;
            }
        }
        for(int k = 1;k <=C; k++){
            for(int i = 1; i <= C; i++){
                for(int j = 1; j <= C; j++){
                    mDis[i][j] = min(mDis[i][j],max(mDis[i][k],mDis[j][k]));
                }
            }
        }
        if(count>0)
            printf("\n");
        printf("Case #%d\n",++count);
        for(int i = 0; i < Q; i++){
            scanf("%d %d",&ia,&ib);
            if(mDis[ia][ib]!=INF)
                printf("%d\n",mDis[ia][ib]);
            else printf("no path\n");
        }
    }
    return 0;
}
