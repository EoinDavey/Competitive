#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) cin >> x >> y >> z
#define rd2(x,y) cin >> x >> y
#define rd(x) cin >> x
#define pr3(x,y,z) cout << x << ' ' << y << ' ' << z << endl
#define pr2(x,y) cout << x << ' ' << y << endl
#define pr(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << ' ' << endl
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 1000; //TODO
map<char, int> in;
map<char, vector<char> > adjList;
set<char> chrs;

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    char u,v;
    while(scanf(" Step %c must be finished before step %c can begin.", &u, &v)==2){
        in[v]+=1;
        adjList[u].pb(v);
        chrs.insert(u);
        chrs.insert(v);
    }
    priority_queue<char, vector<char>, greater<char>> q;
    for(char i : chrs)
        if(in[i]==0)
            q.push(i);
    //vector<char> out;
    int tm = 0;
    int end[5] = {0,0,0,0,0};
    char load[5] = {0,0,0,0,0};

    int cnt = 0;
    while(cnt < sz(chrs)){
        debug(tm);
        for(int i = 0; i < 5; ++i){
            if(load[i] && end[i] <= tm){
                cnt++;
                char u = load[i];
                printf("Task %c finished\n", u);
                for(char v : adjList[u]){
                    in[v]--;
                    if(in[v]==0)
                        q.push(v);
                }
                load[i] = 0;
            }
        }
        while(sz(q)){
            char c = q.top(); q.pop();
            printf("Try to assign %c\n", c);
            bool f = false;
            for(int i = 0; i < 5; ++i){
                if(load[i]==0){
                    printf("Assign to worker %d\n", i+1);
                    f = true;
                    end[i] = tm+60+c-'A'+1;
                    load[i] = c;
                    break;
                }
            }
            if(!f){
                puts("Failed to assign");
                q.push(c);
                break;
            }
        }
        ++tm;
    }
    pr(tm);
    /*
    for(char c : out)
        printf("%c", c);
        */
    return 0;
}
