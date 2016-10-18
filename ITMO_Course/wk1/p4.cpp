#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#define FILE_IN "team.in"
#define FILE_OUT "team.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

int main(){
    int t[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> t[i][j];
        }
    }
    double max = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(i!=j&&i!=k&&k!=j){
                    double c = sqrt(pow(t[0][i],2) + pow(t[1][j],2) + pow(t[2][k],2));
                    if(c>max)max = c;
                }
            }
        }
    }
    cout << fixed << setprecision(11) << max << endl;
    return 0;
}
