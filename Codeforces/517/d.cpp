#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define qu priority_queue
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef complex<double> cc;
typedef priority_queue<int> qi;

const int MX_N = 2002;
const int INF = 1000*1000*1000;
const int mvs[][2] = {0,1,1,0};
char grid[MX_N][MX_N];
int dist[MX_N][MX_N];
int N, K;
vector<ii> chs[30];

inline bool valid(int i, int j){ return i >= 0 && j >= 0 && i < N && j < N;}
int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf(" %c", &grid[i][j]);
    
    //First dist calc
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            dist[i][j] = INF;
    dist[0][0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(i > 0)
                dist[i][j] = min(dist[i][j], dist[i-1][j]);
            if(j > 0)
                dist[i][j] = min(dist[i][j], dist[i][j-1]);
            dist[i][j] += grid[i][j] != 'a';
        }
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(dist[i][j] <= K)
                grid[i][j] = 'a';

    //now find lexicographically least path
    for(int i = 0; i < N; ++i)
        for(int j = 0; j< N; ++j)
            dist[i][j] = 0;
    queue<ii> q;
    q.push({0,0});
    dist[0][0] = 1;
    printf("%c",grid[0][0]);
    for(int k = 1; k < 2*N-1; ++k){
        for(int i = 0; i < 30; ++i)
            chs[i].clear();
        while(!q.empty()){
            ii p = q.front(); q.pop();
            for(int j = 0; j < 2; ++j){
                int nx,ny; nx = p.first + mvs[j][0]; ny = p.second + mvs[j][1];
                if(valid(nx,ny) && !dist[nx][ny]){
                    dist[nx][ny] = 1;
                    chs[grid[nx][ny]-'a'].pb({nx,ny});
                }
            }
        }
        for(int i = 0; i < 30; ++i){
            if(chs[i].size()!=0){
                printf("%c", i+'a');
                for(auto j : chs[i])
                    q.push(j);
                break;
            }
        }
    }
    putchar('\n');
    return 0;
}
