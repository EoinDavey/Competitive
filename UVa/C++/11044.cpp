#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int N,M,T;

int main(){
    cin >> T;
    for(int t = 0; t < T; t++){
        scanf("%d %d",&N,&M);
        printf("%d\n",(N/3)*(M/3));
    }
    return 0;
}
