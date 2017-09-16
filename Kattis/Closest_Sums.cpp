#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

constexpr int INF=100000000;

int main(){
    int ccnt=0;
    int N;
    while(scanf("%d",&N)==1){
        printf("Case %d:\n",++ccnt);
        int a[N];
        for(int i = 0; i < N; ++i)
            scanf("%d",&a[i]);
        unordered_set<int> st;
        for(int i = 0; i < N; ++i)
            for(int j = i+1; j< N; ++j)
                st.insert(a[i]+a[j]);
        int M; scanf("%d",&M);
        int in;
        for(int i = 0; i < M; ++i){
            int mn = INF;
            scanf("%d",&in);
            for(int j : st)
                if(abs(j-in) < abs(in-mn))
                    mn=j;
            printf("Closest sum to %d is %d.\n",in,mn);
        }
    }
    return 0;
}
