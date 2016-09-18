#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    if(s.length()<26){
        cout << -1 << endl;
        return 0;
    }
    bool used[26];
    int qC,c;
    int res = -1;
    for(int i = 0; i <= s.length()-26; i++){
        qC=c=0;
        memset(used,false,sizeof(used));
        for(int j = 0; j < 26; j++){
            if(s[i+j]!='?'){
                int v = ((int)s[i+j]) - ((int)'A');
                if(!used[v])used[v]=true,c++;
                else break;
            }else qC++;
        }
        if(qC+c==26){
            res = i;
            break;
        }
    }
    if(res!=-1){
        for(int i = 0; i < res; i++){
            if(s[i]=='?')printf("A");
            else printf("%c",s[i]);
        }
        for(int i = res; i < res+26; i++){
            if(s[i]=='?'){
                for(int j = 0; j < 26; j++){
                    if(!used[j]){
                        printf("%c",((char)((int)j+((int)'A'))));
                        used[j]=true;
                        break;
                    }
                }
            }else printf("%c",s[i]);
        }
        for(int i = res+26; i < s.length(); i++){
            if(s[i]=='?')printf("A");
            else printf("%c",s[i]);
        }
    } else cout << -1;
    cout << endl;
    return 0;
}
