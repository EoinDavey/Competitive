#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#define FILE_IN "chairs.in"
#define FILE_OUT "chairs.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

int main(){
    double A,B,C;
    cin >> A >> B >> C;
    cout << fixed << setprecision(10) << (A/2.0 + B/2.0 + C/2.0)/3.0 << endl;
    return 0;
}
