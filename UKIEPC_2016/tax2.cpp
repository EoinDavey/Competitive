#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<iomanip>

using namespace std;

int N;
double ep = pow(10,-7);
double bands[21][2];
double taxedIn;

double calculate(double x){
    double t = x;
    double cost = 0.0;
    for(int i = N; i >0; i--){
        if(t<bands[i-1][0])continue;
        double c = t-bands[i-1][0];
        cost+= c*(1-bands[i][1]);
        t -= c;
    }
    cost+= t/(1-bands[0][1]);
    return cost;
}

double search(double L, double R, double target){
    double mid = (L+R)/2;
    double res = calculate(mid);
    if(abs(res - target)<ep) return mid;
    if(target < res){
        return search(L, mid, target);
    } else return search(mid, R, target);
}

int main(){
    cin >> N;
    double u,p;
    double lim = 0;
    for(int i = 0; i < N; i++){
        cin >> u >> p;
        lim+=u;
        p = p/100;
        bands[i][0] = lim;
        bands[i][1] = p;
    }
    bands[N][0] = 1000000000.0;
    cin >> bands[N][1];
    bands[N][1]/=100;
    for(int i = 0; i <=N; i++){
        cout << bands[i][0] << "," << bands[i][1] << endl;
    }
    int C;
    cin >> C;
    double start,in;
    for(int i = 0; i < C; i++){
        cin >> start >> in;
        taxedIn = calculate(start);
        cout << fixed << search(0, 1000000000.0, taxedIn+in) - start << endl;
    }
    return 0;
}
