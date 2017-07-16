#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

int N;
int tree[40000][2];
int a[10011];

// Segment tree query
int query(int v, int L, int R, int l, int r,bool o){
    if(l>r)
        return 0;
    if(L >= l && R <= r)
        return tree[v][o];
    if(R<l || L>r)
        return -1;
    int m = (L+R)/2;
    return max(query(2*v,L,m,l,r,o),query(2*v+1,m+1,R,l,r,o));
}

// Segment tree update
void update(int v, int L, int R, int p, int val,bool o){
    if(L==R){
        tree[v][o]=val;
        return;
    }
    int m = (L+R)/2;
    if(m >= p)
        update(2*v,L,m,p,val,o);
    else
        update(2*v+1,m+1,R,p,val,o);
    tree[v][o]=max(tree[2*v][o],tree[2*v+1][o]);
}

int main(){
    while(scanf("%d",&N)==1){
        int in[N];
        memset(tree,0,sizeof(tree));
        for(int i = 0; i < N; i++){
            scanf("%d",&a[i]);
            in[i]=a[i];
        }
        // Map input to range (0,N)
        sort(in,in+N);
        map<int,int> m;
        for(int i= 0; i < N; i++)
            m[in[i]]=i;
        for(int i = 0; i < N; i++)
            a[i]=m[a[i]];
        int rev[N];
        for(int i = 0; i < N; i++)
            rev[i]=a[N-i-1];
        int lm[N],rm[N];
        // O(NlogN) LIS and DIS algorithm
        for(int i = 0; i < N; i++){
            int v = query(1,0,N-1,0,a[i]-1,0);
            update(1,0,N-1,a[i],v+1,0);
            lm[i] = v+1; // Store LIS here
            v = query(1,0,N-1,0,rev[i]-1,1);
            update(1,0,N-1,rev[i],v+1,1);
            rm[N-i-1] = v+1; // Store DIS here
        }
        int b = 0;
        for(int i = 0; i < N; i++)
            b = max(b,(min(rm[i],lm[i])-1)*2 + 1);
        printf("%d\n",b);
    }
    return 0;
}
