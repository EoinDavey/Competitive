#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct rr {
    ll st,ln;
    rr(ll _st, ll _end) : st(_st), ln(_end) {}
    rr(){}
    bool operator < (const rr &r) const {
        if(st!=r.st)
            return st < r.st;
        return ln < r.ln;
    }
};

const int MX_N = 300003;
int N;
ll M;
rr rlist[MX_N];

int main(){
    scanf("%d %lld",&N,&M);
    for(int i = 0; i < N; i++)
        scanf("%lld %lld",&rlist[i].st,&rlist[i].ln);
    sort(rlist,rlist+N);
    priority_queue<ll,vector<ll>, greater<ll> > q;
    ll st,ln;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        st = rlist[i].st;ln = rlist[i].ln;
        while(!q.empty() && q.top() + M < st){
            q.pop();
        }
        if(!q.empty() && q.top() <= st){
            cnt++;
            q.pop();
        }
        q.push(st+ln);
    }
    printf("%d\n",cnt);
    return 0;
}
