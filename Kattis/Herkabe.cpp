#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000;
const ll MD = INF+7LL;
const int MX_N = 3003;
char buff[3003];
ll fac[28];

struct node {
    int chind[26];
    vector<node *> children;
    int chcnt;
    bool end;
    node(){
        memset(chind,-1,sizeof(chind));
        chcnt=0;
        end = false;
    }
} * root;

ll trav(node *nd){
    ll o = fac[nd->chcnt + nd->end];
    for(node * v : nd->children)
        o=(o*trav(v))%MD;
    return o%MD;
}

int main(){
    fac[0] = 1LL;
    for(int i = 1; i<=27; ++i)
        fac[i] = (fac[i-1] * ((ll)i)) % MD;
    int N; scanf("%d",&N);
    char c;
    root = new node();
    for(int i = 0; i < N;++i){
        while(c < 'A' || c > 'Z')
            c = getchar_unlocked();
        node * nd = root;
        while(c >= 'A' && c <= 'Z'){
            int ind = c-'A';
            if(nd->chind[ind]==-1){
                nd->chind[ind] = nd->chcnt++;
                nd->children.push_back(new node());
            }
            nd = nd->children[nd->chind[ind]];
            c = getchar_unlocked();
        }
        nd->end=true;
    }
    printf("%lld\n",trav(root));
    delete root;
    return 0;
}
