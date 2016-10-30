#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<iomanip>

using namespace std;

int main(){
    int B;
    cin >> B;
    double bands[B+1][2];
    double cnt = 0;
    for(int i = 0; i < B; i++){
        double s,p;
        cin >> s >> p;
        bands[i][0] = cnt+s;
        bands[i][1] = p/100.0;
        cnt+=s;
    }
    bands[B][0] = 10000000000;
    cin >> bands[B][1];
    bands[B][1]/=100.0;
    int F;
    cin >> F;
    double in, target;
    for(int i = 0; i < F; i++){
        cin >> in >> target;
        target+=in;
        double base = in;
        double count = 0.0;
        for(int  j = 0; j <= B; j++){
            if(bands[j][0] < base)continue;
            double tmp = bands[j][0];
            if(target<bands[j][0]){
                bands[j][0] = target;
            }
            count+= (bands[j][0]-base)*(1.0/(1.0-bands[j][1]));
            cout << count << endl;
            base = bands[j][0];
            bands[j][0] = tmp;
        }
        cout <<fixed<< setprecision(8) << count << endl;
    }
    return 0;
}
