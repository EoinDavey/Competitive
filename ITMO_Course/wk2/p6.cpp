#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<stack>
#define FILE_IN "snowmen.in"
#define FILE_OUT "snowmen.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

vector<pair<int, int> > snowmen;

int main(){
    long long int total = 0;
    snowmen.push_back(make_pair(0,0));
    int N;
    cin >> N;
    int A,B;
    for(int i = 0; i < N; i++){
        cin >> A >> B;
        if(B!=0){
            snowmen.push_back(make_pair(snowmen[A].first+B,A));
            total+=(long long int)snowmen[A].first+B;
        } else{
            snowmen.push_back(make_pair(snowmen[snowmen[A].second].first,snowmen[snowmen[A].second].second));
            total+=(long long int)snowmen[snowmen[A].second].first;
        }
    }
    cout << total << endl;
    return 0;
}
