#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<sstream>

using namespace std;

map<string,int> mp;

int main(){
    int N; scanf("%d",&N);
    string in,country;
    getline(cin,in);
    for(int i = 0; i < N; i++){
        getline(cin,in);
        stringstream s(in);
        s >> country;
        mp[country]++;
    }
    for(map<string,int>::iterator i = mp.begin(); i!=mp.end(); i++){
        cout << i->first << " " << i->second << endl;
    }
    return 0;
}
