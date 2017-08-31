#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
ll N;
int M;
const int MX_M=500005;
bool st[MX_M];
int L[MX_M];
int R[MX_M];
ll count[MX_M];
bool vis[MX_M];

vector<int> adjList[MX_M];

vector<int> order;

void topSort(int v){
    vis[v]=true;
    for(auto i = adjList[v].begin(); i != adjList[v].end(); i++){
        if(!vis[*i])
            topSort(*i);
    }
    order.push_back(v);
}

int main(){
    scanf("%lld %d",&N,&M);
    char in;
    for(int i = 1; i <= M; i++){
        scanf(" %c %d %d",&in,&L[i],&R[i]);
        st[i]= in=='L';
        adjList[L[i]].push_back(i);
        adjList[R[i]].push_back(i);
    }
    topSort(0);
    count[1]=N;
    for(auto i = order.begin(); i != order.end(); i++){
        if(*i==0)
            break;
        ll c = count[*i];
        ll s = c>>1;
        ll l = c-s;
        if(st[*i]){
            count[L[*i]]+=l;
            count[R[*i]]+=s;
        } else {
            count[L[*i]]+=s;
            count[R[*i]]+=l;
        }
        if(c%2L!=0)
            st[*i] = !st[*i];
    }
    for(int i = 1; i <= M;i ++)
        if(st[i])
            putchar('L');
        else
            putchar('R');
    putchar('\n');
    return 0;
}
