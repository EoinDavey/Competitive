#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
    int res = 0;
    char c;
    int in,n;
    bool b = true;
    bool minus = false;
    while(1){
        if(b){
           scanf("%d",&in);
           if(minus)
               res-=in,minus=false;
           else res+=in;
        }else{
            if(scanf("%c",&c)==0)
                break;
            if(c=='-')
                minus = true;
            if(c=='\n')
                break;
        }
        b=!b;
    }
    string s = to_string(res);
    char prev = '0';
    cout << "++++++[>++++++++<-]>";
    for(int i = 0; i < s.length(); i++){
        if(s[i]>=prev)
            for(int j = 0; j < (s[i]-prev); j++)
                printf("+");
        else
            for(int j = 0; j < prev-s[i]; j++)
                printf("-");
        printf(".");
        prev = s[i];
    }
    cout << endl;
    return 0;
}
