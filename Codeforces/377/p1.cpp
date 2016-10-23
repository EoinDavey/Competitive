#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int K, r;

int main(){
    cin >> K >> r;
    int dif = K%10;
    int c = dif;
    int i = 1;
    while(c!=r&&c!=0){
        c=(c+dif)%10;
        i++;
    }
    cout << i << endl;
    return 0;
}
