#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;

constexpr double EPS = 1e-7;

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        int M;
        double D,R;
        scanf("%d %lf",&M,&D);
        R=D/2.0;
        cc m[M];
        double x,y;
        for(int i = 0; i < M; ++i){
            scanf("%lf %lf",&x,&y);
            m[i] = cc(x,y);
        }
        int mx = M>0;
        for(int i = 0; i < M; ++i){
            for(int j = i+1; j < M; ++j){
                cc md = (m[i]+m[j])/2.0;
                cc v1 = md-m[i];
                double q = abs(v1);
                if(q > R)
                    continue;
                double d = sqrt(R*R - q*q);
                cc mir = d*((cc(0,1) * v1)/q);
                cc p1 = md+mir;
                cc p2 = md-mir;
                int cnt = 0;
                for(int k = 0; k < M; ++k){
                    if(abs(m[k]-p1)-EPS <= R)
                        cnt++;
                }
                mx = max(cnt,mx);
                cnt = 0;
                for(int k = 0; k < M; ++k){
                    if(abs(m[k]-p2)-EPS <= R)
                        cnt++;
                }
                mx = max(cnt,mx);
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
