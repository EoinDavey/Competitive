#include<bits/stdc++.h>
using namespace std;

typedef complex<double> cc;

int main(){
    int T; scanf("%d",&T);
    while(T-- > 0){
        double heading=90.0;
        cc pos(0,0);
        int N; scanf("%d",&N);
        double t,d;
        for(int i = 0; i < N; i++){
            scanf("%lf %lf",&t,&d);
            heading += t;
            cc move = polar(d,heading*M_PI/180.0);
            pos += move;
        }
        printf("%lf %lf\n",real(pos),imag(pos));
    }
    return 0;
}
