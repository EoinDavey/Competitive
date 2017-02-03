#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N,A,B,K;

int main(){
    cin >> N >> A >> B >> K;
    char c;
    bool g[N];
    for(int i = 0; i < N; i++){
        scanf(" %c",&c);
        g[i] = c - '0';
    }
    int p,cnt;
    p = cnt = 0;
    vector<int> pos;
    for(int i = 0; i < N; i++){
        if(!g[i])cnt++;
        else {
            cnt=0;
        }
        if(cnt == B){
            cnt=0;
            p++;
            pos.push_back(i);
        }
    }
    cout << p - A + 1 << endl;
    for(int i = 0; i < p-A+1; i++){
        if(i>0)cout << " ";
        cout << pos[i] + 1;
    }
    cout << endl;
    return 0;
}
