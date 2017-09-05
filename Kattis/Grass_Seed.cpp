#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<iomanip>

using namespace std;

double C;
int L;

int main(){
    cin >> C;
    cin >>L;
    double cost = 0;
    for(int i = 0; i < L; i++){
        double w,l;
        cin >> w >> l;
        cost+= (w*l)*C;
    }
    cout << setprecision(10) << cost << endl;
    return 0;
}
