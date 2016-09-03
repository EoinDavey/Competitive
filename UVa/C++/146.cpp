#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

const int lim = 50;
char input[lim];

int main(){
    char c;
    int cnt = 0;
    while(scanf("%c",&c),c!='#'){
        if(c!='\n'){
            input[cnt++]=c;
        }else{
            bool b = next_permutation(input,input+cnt);
            if(b){
                for(int i = 0; i < cnt; i++){
                    printf("%c",input[i]);
                }
                cout << endl;
            } else cout << "No Successor" << endl;
            cnt=0;
        }
    }
    return 0;
}
