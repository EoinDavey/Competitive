#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main(){
    int N;scanf("%d",&N);
    char s[N]; scanf(" %s",s);
    stringstream ss;
    int i = 0;
    for(i = 0; i < N-2; i++){
        if(s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o'){
            ss << "***";
            for(; i < N-2; i+=2){
                if(s[i+1]!='g'||s[i+2]!='o')break;
            }
        }else ss << s[i];
    }
    for(; i < N; i++)ss<<s[i];
    cout << ss.str() << endl;
    return 0;
}
