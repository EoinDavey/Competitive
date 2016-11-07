#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#define FILE_IN "stacks.in"
#define FILE_OUT "stacks.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

vector<int> stacks;
int lastMin = 0;

int main(){
    int N;
    cin >> N;
    int nonEmpty= 0;
    int a;
    bool newStack=false;
    for(int i = 0; i < N; i++){
    }
    cout << stacks[0] << endl;
    return 0;
}
