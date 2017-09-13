#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string in;
    int N; cin >> N;
    getline(cin,in);
    while(~--N){
        getline(cin,in);
        bool az[26];
        memset(az,0,sizeof(az));
        for(char c : in)
            if(c >= 'a' && c <= 'z')
                az[c-'a']=true;
            else if(c >= 'A' && c <= 'Z')
                az[c-'A']=true;
        bool f=false;
        for(int i = 0; i < 26; i++)
            if(!az[i])
                f=true;
        if(f){
            cout << "missing ";
            for(int i = 0; i < 26; i++)
                if(!az[i])
                    cout << ((char)(i+'a'));
            cout << endl;
        } else
            cout << "pangram\n";
    }
    return 0;
}
