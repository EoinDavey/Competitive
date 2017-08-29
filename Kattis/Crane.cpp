#include<bits/stdc++.h>
using namespace std;

const int MX_N = 10001;
int N;
int a[MX_N];
int t[MX_N];
int pos[MX_N];

void move(int u, int v){
    int sz = (v-u+1)/2;
    for(int i = 0; i < sz; i++)
        t[i] = a[u+i];
    for(int i = 0; i < sz; i++)
        a[u+i] = a[u+sz+i];
    for(int i = 0; i < sz; i++)
        a[u+sz+i] = t[i];
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        scanf("%d",&N);
        for(int i = 0; i < N; i++)
            scanf("%d",&a[i]),a[i]--;
        vector<pair<int,int > > ps;
        for(int i = 0; i < N;){
            int ind=-1;
            for(int j = i; j < N; j++){
                if(a[j]==i){
                    ind = j;
                    break;
                }
            }
            if(ind==i){
                i++;
                continue;
            }
            int tailLength = N-i;
            if(i+(ind-i)*2 - 1 >= N){
                if(tailLength%2==0){
                    move(i,N-1);
                    ps.push_back(make_pair(i,N-1));
                } else {
                    move(i+1,N-1);
                    ps.push_back(make_pair(i+1,N-1));
                }
                continue;
            }
            move(i,i+(ind-i)*2-1);
            ps.push_back(make_pair(i,i+(ind-i)*2 - 1));
            i++;
        }
        printf("%lu\n",ps.size());
        for(int i = 0; i < ps.size(); i++)
            printf("%d %d\n",ps[i].first+1,ps[i].second+1);
    }
    return 0;
}
