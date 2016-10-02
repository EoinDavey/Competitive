#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N;

int main(){
    cin >> N;
    char in;
    bool b = true;
    int x1,y1,x2,y2;
    x1=y1=x2=y2=0;
    for(int i = 0; i < N; i++){
        scanf("%c",&in);
        if(in=='\n'){
            i--;
            continue;
        }
        if(in=='r'){
            if(b)x1++;
            else x2++;
        } else{
            if(b)y2++;
            else y1++;
        }
        b=!b;
    }
    int i = max(x1,y1);
    int j = max(x2,y2);
    cout << min(i,j) << endl;
    return 0;
}
