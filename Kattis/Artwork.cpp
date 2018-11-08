#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define ii pair<int, int>
#define fi first
#define se second
#define mk make_pair
#define mt make_tuple
struct edge{ int x1,y1,x2,y2; };

const int MX_N = 1001;
const int moves[][2] = {0,1,1,0,0,-1,-1,0};
int grid[MX_N][MX_N];
int p[MX_N*MX_N];
int N, M, Q;
int totseg = 0;
vector<edge> edges;

int find(int i){return p[i] = (i==p[i] || i==-1 ? i : find(p[i]));}
void join(int a, int b){
	a = find(a);
	b = find(b);
	if(a <0 || b < 0 || a==b)
		return;
	p[a] = b;
	--totseg;
}
int coord(int x, int y){ return x*M + y;}
bool valid(int i, int j) {return i >= 0 && j >= 0 && i < N && j < M;}
void open(int x, int y){
	int c = coord(x,y);
	if(p[c] == -1){
		++totseg;
		p[c] = c;
	}
	for(int k = 0; k < 4; ++k){
		int nx,ny;nx=x+moves[k][0];ny=y+moves[k][1];
		if(valid(nx,ny) && grid[nx][ny] == 0)
			join(c, coord(nx,ny));
	}
}

int main(){
	memset(p, -1, sizeof(p));
	scanf("%d %d %d", &N, &M, &Q);
	int x1,y1,x2,y2;
	for(int i = 0; i < Q; ++i){
		scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
		--x1,--y1,--x2,--y2;
		edges.pb({x1,y1,x2,y2});
	}
	for(auto& e : edges){
		x1=e.x1; x2=e.x2; y1=e.y1; y2=e.y2;
		if(x1 == x2){
			//vertical
			for(;y1 <= y2; ++y1){
				grid[x1][y1]+=1;
			}
		} else {
			//horizontal
			for(;x1 <= x2; ++x1){
				grid[x1][y1]+=1;
			}
		}
	}
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			if(grid[i][j] == 0)
				open(i,j);
	vector<int> ans;
	for(auto i = edges.rbegin(); i != edges.rend(); i++){
		ans.pb(totseg);
		x1=i->x1; x2=i->x2; y1=i->y1; y2=i->y2;
		if(x1==x2){
			//vertical
			for(;y1 <= y2; ++y1){
				grid[x1][y1]-=1;
				if(grid[x1][y1] == 0)
					open(x1,y1);
			}
		} else {
			//horizontal
			for(;x1 <= x2; ++x1){
				grid[x1][y1]-=1;
				if(grid[x1][y1] == 0)
					open(x1,y1);
			}
		}
	}
	for(auto i = ans.rbegin(); i != ans.rend(); i++)
		printf("%d\n", *i);
	return 0;
}
