#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#define FILE_IN "prepare.in"
#define FILE_OUT "prepare.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

int N,p[101],t[101];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    for(int i = 0; i < N; i++){
        cin >> t[i];
    }
    int minDif,pCount,tCount,prep;
    minDif = 20000;
    prep = pCount=tCount=0;
    for(int i = 0; i < N; i++){
        int dif = abs(p[i] - t[i]);
        if(dif<minDif)minDif=dif;
        if(p[i]>t[i]){
            pCount++;
            prep+=p[i];
        } else {
            tCount++;
            prep+=t[i];
        }
    }
    if(pCount == 0||tCount==0)prep-=minDif;
    cout << prep << endl;
    return 0;
}
