#include<bits/stdc++.h>
using namespace std;

int main(){
    int nx,ny;
    double w;
    while(scanf("%d %d %lf",&nx,&ny,&w), nx|ny && (w!=0.0)){
        double in;
        vector<double> lnth,wdth;
        for(int i = 0; i < nx; i++){
            scanf("%lf",&in);
            lnth.push_back(in-w/2.0);
        }
        sort(lnth.begin(), lnth.end());
        bool lFail=false;
        for(int i = 0; i < nx-1&&lFail; i++){
            double l = max(0.0,lnth[i]);
            double nxt = max(0.0, lnth[i+1]);
            if(nxt-l > w)
                lFail=true;
        }
        if(lnth[0] > 0 || lnth[nx-1]+w < 75.0)
            lFail = true;
        for(int i = 0; i < ny; i++){
            scanf("%lf",&in);
            wdth.push_back(in-w/2.0);
        }
        sort(wdth.begin(), wdth.end());
        bool wFail=false;
        for(int i = 0; i < ny-1&&!wFail; i++){
            double l = max(0.0,wdth[i]);
            double nxt = max(0.0, wdth[i+1]);
            if(nxt-l > w)
                wFail=true;
        }
        if(wdth[0] > 0 || wdth[ny-1]+w < 100.0)
            wFail = true;
        if(wFail || lFail)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
