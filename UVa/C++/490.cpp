#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

string grid[101];

int main(){
    int n = 0;
    int mx = 0;
    while(getline(cin,grid[n++])){
        if(grid[n-1].length()>mx)mx=grid[n-1].length();
    }
    for(int i = 0; i < mx; i++){
        for(int j = n-2; j >= 0; j--){
            if(grid[j].size() >= i+1){
                cout << grid[j][i];
            } else cout << " ";
        }
        cout << endl;
    }
    return 0;
}
