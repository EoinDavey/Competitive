#include<bits/stdc++.h>
using namespace std;
int N,lim;
char * buff = new char[2000002];

inline bool check(int s){
    for(int i = 0; i < N; i+=s){
        for(int j = 0; j < s; j++){
            if(buff[i+j]!=buff[j])
                return false;
        }
    }
    return true;
}

int main(){
    while(scanf("%s",buff)){
        if(*buff=='.')
            break;
        N = strlen(buff);
        scanf("%d", &N);
        lim = (int) ceil(sqrt((double) N));
        int mn = 10000000;
        vector<int> factors;
        for(int i = 1; i <= lim; i++)
            if(N%i==0)
                factors.push_back(i), factors.push_back(N/i);
        sort(factors.begin(), factors.end());
    }
    delete buff;
    return 0;
}
