#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define ii pair<int, int>
#define fi first
#define se second
#define mk make_pair
#define mt make_tuple
#define X real
#define Y imag
#define N 1000007   //10e6 + 7

complex<double>pts[2][N];
typedef complex<double> cc;

double dist(int i, int x){ // dist between curr and curr+1
	return abs(pts[x][i]-pts[x][i+1]);
}

struct lseg{
	complex<double>p, q;
};

double dot(cc a, cc b){
	return X(a) * X(b) + Y(a) * Y(b);
}

double distptline(cc p, cc a, cc b){
	if(abs(a-b)<=1e-6)return abs(a);
	cc ap = p-a;
	cc ab = b-a;
	double u = dot(ap,ab)/dot(ab,ab);
	if(u < 0.0)
		return abs(ap);
	if(u > 1.0)
		return abs(p-b);
	cc c = a+ab*u;
	return abs(c-p);
}

int main(){
	int n, m;
	cin >> n;
	

	for(int i=0; i<n; i++){
		double x, y;
		cin >> x >> y;
		pts[0][i]={x, y};
	}
	cin >> m;

	for(int i=0; i<m; i++){
		double x, y;
		cin >> x >> y;
		pts[1][i]={x, y};
	}
	
	int curr[] = {0, 0};
	double ans=1000000000000.0;
	complex<double>zero = {0,0};

	while(curr[0]!=n-1 and curr[1]!=m-1){
		complex<double>tmp;
		if(dist(curr[0], 0)<dist(curr[1], 1)){		// first line is shorter
			tmp=pts[1][curr[1]]+dist(curr[0], 0)*(pts[1][curr[1]+1]-pts[1][curr[1]])/dist(curr[1], 1);
			ans=min(ans, distptline(zero, pts[0][curr[0]]-pts[1][curr[1]], pts[0][curr[0]+1]-tmp));
			curr[0]++;
			pts[1][curr[1]]=tmp;
		}else if(dist(curr[0], 0)>dist(curr[1], 1)){						// second line is shorter
			tmp=pts[0][curr[0]]+dist(curr[1], 1)*(pts[0][curr[0]+1]-pts[0][curr[0]])/dist(curr[0], 0);
			ans=min(ans, distptline(zero, pts[0][curr[0]]-pts[1][curr[1]], tmp-pts[1][curr[1]+1]));
			curr[1]++;
			pts[0][curr[0]]=tmp;
		}else{
			ans=min(ans, distptline(zero, pts[0][curr[0]]-pts[1][curr[1]], pts[0][curr[0]+1]-pts[1][curr[1]+1]));
			curr[0]++;
			curr[1]++;
		}
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
