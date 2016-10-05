#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int in[3];
    for(int i = 0; i < 3; i++){
        scanf("%d",&in[i]);
    }
    sort(in,in+3);
    cout << (in[1]-in[0]) + (in[2]-in[1]) << endl;
    return 0;
}
