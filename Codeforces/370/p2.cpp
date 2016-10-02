#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

string in;
int main(){
    getline(cin,in);
    int up,right;
    for(int i = 0; i < in.length(); i++){
        if(in[i]=='U')up++;
        if(in[i]=='D')up--;
        if(in[i]=='L')right--;
        if(in[i]=='R')right++;
    }
    if((in.length()&2)!=0){
        cout << -1 << endl;
        return 0;
    }
    bool vP = ((up&1)==0);
    bool hP = ((right&1)==0);
    int output=0;
    if(vP&&hP){
        output+=up/2;
        output+=right/2;
    }

    return 0;
}
