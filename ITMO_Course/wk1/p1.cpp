#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#ifdef JUDGE
#include<fstream>
std::ifstream cin("aplusb.in");
std::ofstream cout("aplusb.out");
#else
#include<iostream>
#endif

using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    cout << A + B << endl;
    return 0;
}
