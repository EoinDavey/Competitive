#include<bits/stdc++.h>
using namespace std;
typedef struct{int x,y;} pt;
struct circ{pt c;int r;};
const int MX_N = 202;
int p[MX_N];
int N;

int find(int i){return p[i] = (p[i]==i ? i : find(p[i]));}
void join(int a, int b){ p[find(a)] = find(b); }

int sq(int x){return x*x;}
bool insct(const circ& a, const circ& b){
    return sq(a.c.x-b.c.x) + sq(a.c.y-b.c.y) <= sq(a.r+b.r);
}

bool check(const vector<circ>& c){
    for(int i = 0; i < N; ++i)
        p[i]=i;
    for(int i=0; i < c.size(); ++i)
        for(int j = 0; j < i; ++j)
            if(insct(c[i],c[j]))
                join(i,j);
    int L[N], R[N];
    for(int i = 0; i < N; ++i)
        L[i]=2000,R[i]=-2000;
    for(int i = 0; i < c.size(); ++i){
        int st = find(i);
        L[st] = min(L[st], c[i].c.x-c[i].r);
        R[st] = max(R[st], c[i].c.x+c[i].r);
    }
    for(int i = 0; i < N; ++i)
        if(p[i]==i && L[i] <= 0 && R[i] >= 200)
            return true;
    return false;
}

int main(){
    scanf("%d",&N);
    int x,y,r;
    vector<circ> c;
    for(int i = 0; i < N; ++i){
        scanf("%d %d %d",&x,&y,&r);
        c.push_back({pt{x,y},r});
        if(check(c)){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
