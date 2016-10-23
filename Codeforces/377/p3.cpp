#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

long long int meals[3];

int main(){
    long long int mx = 0;
    for(int i = 0; i < 3; i++){
        scanf("%lld",&meals[i]);
        if(meals[i] > mx)mx = meals[i];
    }
    long long int cnt = 0;
    for(int i = 0; i < 3; i++){
        if(meals[i]+1<mx)cnt+=mx-meals[i]-1;
    }
    cout << cnt<<endl;
    return 0;
}
