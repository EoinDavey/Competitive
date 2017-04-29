#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#define FILE_IN "win.in"
#define FILE_OUT "win.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    int cs = 0;
    int it = 0;
    while(cs<=(300*60)){
        cs+=arr[it];
        it++;
    }    
    cout << it-1 << endl;
    return 0;
}
