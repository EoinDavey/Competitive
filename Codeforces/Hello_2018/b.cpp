#include<bits/stdc++.h>
using namespace std;

const int MX_N=1011;
int cnt[MX_N];
vector<int> ch[MX_N];

int main(){
    int N; scanf("%d",&N);
    int p;
    for(int i = 0; i < N-1; ++i){
        scanf("%d",&p);
        cnt[p-1]++;
        ch[p-1].push_back(i+1);
    }
    bool b=false;
    for(int i = 0; i < N && !b; ++i){
        int c = 0;
        for(auto j : ch[i])
            if(cnt[j]==0)
                c++;
        if(cnt[i]>0 && c<3)
            b=true;
    }
    if(b)
        puts("No");
    else
        puts("Yes");
    return 0;
}
