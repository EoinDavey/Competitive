#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

unsigned int A,B;

int main(){
    while(scanf("%u %u",&A,&B)==2){
        unsigned int out = A^B;
        cout << out << endl;
    }
    return 0;
}
