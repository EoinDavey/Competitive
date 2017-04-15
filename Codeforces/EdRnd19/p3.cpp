#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

const int mx_n = 100001;
char a[mx_n];
char mn[mx_n];

int main(){
    char c;
    int cnt = 0;
    while(true){
        scanf("%c",&c);
        if(c=='\n')
            break;
        a[cnt++] = c;
    }
    mn[cnt] = 'z'+1;
    mn[cnt-1] = a[cnt-1];
    for(int i = cnt-2; i>=0; i--){
        mn[i] = min(a[i],mn[i+1]);
    }
    stack<char> s;
    for(int i = 0; i < cnt; i++){
        s.push(a[i]);
        while(!s.empty() && s.top() <= mn[i+1])
            printf("%c",s.top()),s.pop();
    }
    printf("\n");
    return 0;
}
