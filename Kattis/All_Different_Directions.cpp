#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;

int main(){
    ios::sync_with_stdio(false);
    string in;
    double x,y;
    while(true){
        int N; cin >> N;
        if(N==0)
            break;
        cc avg(0,0);
        getline(cin,in);
        vector<cc> dests;
        for(int i = 0; i < N; i++){
            getline(cin,in);
            stringstream s(in);
            s >> x >> y;
            cc pos(x,y);
            s >> in;
            double heading;
            s >> heading;
            while(s >> in >> x){
                if(in=="turn")
                    heading+=x;
                else if(in=="walk")
                    pos += polar(x,heading*(M_PI/180));
            }
            avg+=pos;
            dests.push_back(pos);
        }
        avg/=((double)N);
        double mxd = 0.0;
        for(auto j = dests.begin(); j != dests.end(); j++)
            mxd = max(mxd,abs(avg-*j));
        printf("%lf %lf %lf\n",real(avg),imag(avg),mxd);
    }
    return 0;
}
