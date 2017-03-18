#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string in;
int n;
int b[1000010];

void preProcess(int v){
    int i = 0;
    int j = -1;
    b[0] = -1;
    while(i < v){
        while(j >= 0 && in[i] != in[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

int search(int v){
    int i, j, cnt;
    i = j = cnt = 0;
    while(i < n){
        while(j>=0 && in[i] != in[j]) j = b[j];
        i++; j++;
        if(j==v){
            cnt++;
            j = 0;
        }
    }
    return cnt;
}

int main(){
    while(getline(cin,in)){
        if(in==".")
            break;
        n = in.length();
        vector<int> factors;
        for(int i = 1; i <= sqrt(n); i++){
            if(n%i==0){
                factors.push_back(i);
                factors.push_back(n/i);
            }
        }
        sort(factors.begin(), factors.end());
        for(int i= 0; i < factors.size(); i++){
            int v = factors[i];
            preProcess(v);
            if(search(v)==n/v){
                cout << n/v << endl;
                break;
            }
        }
    }
    return 0;
}
