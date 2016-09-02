#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(){
    string s;
    string before;
    string after;
    getline(cin,s);
    int c = 0;
    int d = 0;
    bool dec = false;
    bool sig = false;
    for(int i = 0; i < s.length(); i++){
        if(!dec&&!sig&&s[i]=='0')continue;
        if(!dec&&s[i]!='.'){
            before.push_back(s[i]);
            c++;
            if(!sig)sig=!sig;
        }else if(s[i]=='.'){
            dec = true;
        }else if(dec&&!sig&&s[i]=='0'){
            after.push_back(s[i]);
            d++;
        }else if(dec){
            sig = true;
            after.push_back(s[i]);
        }
       // printf("C:%d,D:%d,dec:%d,sig:%d\n",c,d,dec,sig);
    }
    //printf("C:%d,D:%d,dec:%d,sig:%d\n",c,d,dec,sig);
   // cout << before << endl;
    if(c>0){
        int alim = after.length()-1;
        for(; alim >= 0; alim--){
            if(after[alim]!='0')break;
        }
        int blim = before.length()-1;
        if(alim<=0){
            for(;blim>=0;blim--){
                if(before[blim]!='0')break;
            }
        }
        cout << before[0];
        if(alim>=0||blim>0)cout<<'.';
        for(int i = 1; i <= blim; i++){
            cout << before[i];
        }
        for(int i = 0; i <= alim; i++){
            cout << after[i];
        }
        if(c>1){
            printf("E%d",c-1);
        }
    } else {
        int blim = 0;
        for(;blim<after.length();blim++){
            if(after[blim]!='0')break;
        }
        int alim = after.length()-1;
        for(; alim >= 0; alim--){
            if(after[alim]!='0')break;
        }
        cout << after[blim];
        if(alim-blim>0)cout << '.';
        for(int i = blim+1; i <= alim; i++){
            cout << after[i];
        }
        printf("E%d",-d-1);
    }
    cout << endl;
    return 0;
}
