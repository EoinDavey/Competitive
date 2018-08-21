#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;

struct read { cc pos; int t; };

inline double dist(const read& a, const read& b){
  return abs(a.pos - b.pos);
}

int main(){
  int n, t; scanf("%d %d", &n, &t);
  vector<read> pts;
  int x_,y_,t_;
  for(int i = 0; i < n; ++i){
    scanf("%d %d %d", &x_, &y_, &t_);
    pts.push_back({cc(x_,y_), t_});
  }
  double rD,gD; rD=gD=0.0;
  int gt = 0;
  cc prevPos = pts.front().pos;
  for(int i = 1; i < n; ++i){
    rD += dist(pts[i-1], pts[i]);
    while(gt >= pts[i-1].t && gt <= pts[i].t){
      double relT = ((gt - pts[i-1].t)*1.0)/(pts[i].t - pts[i-1].t);
      cc newPos = pts[i-1].pos + relT*(pts[i].pos - pts[i-1].pos);
      gD += abs(newPos - prevPos);
      prevPos = newPos;
      gt+=t;
    }
  }
  gD += abs(pts.back().pos - prevPos);
  double loss = abs((rD - gD)*100.0/rD);
  printf("%.8lf\n",loss);
  return 0;
}
