#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        int N; scanf("%d",&N);
        cc pos(0,0);
        char buff[30];
        double heading=0;
        double d;
        for(int i = 0; i < N; ++i){
            scanf("%s %lf",buff,&d);
            if(buff[0]=='l')
                heading+=d;
            else if(buff[0]=='r')
                heading-=d;
            else if(buff[0]=='f')
                pos+=polar(d,heading*(M_PI/180.0));
            else if(buff[0]=='b')
                pos+=polar(-d,heading*(M_PI/180.0));
        }
        printf("%.lf\n",abs(pos));
    }
    return 0;
}
