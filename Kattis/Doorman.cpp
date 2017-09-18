#include<bits/stdc++.h>
using namespace std;

int main(){
    int X; scanf("%d",&X);
    char s[111];
    scanf("%s",s);
    stack<int> q;
    for(int i = strlen(s)-1; i >= 0;--i)
        q.push(s[i]=='M');
    int cnt = 0;
    int m,w;m=w=0;
    int a,b;
    while(q.size() > 1){
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        int r;
        if(m > w){
            if(a==0){
                r = 0;
                q.push(b);
            } else if(b==0){
                r = 0;
                q.push(a);
            } else {
                r = 1;
                q.push(b);
            }
        } else if(w > m){
            if(a==1){
                r = 1;
                q.push(b);
            } else if(b==1){
                r = 1;
                q.push(a);
            } else {
                r = 0;
                q.push(b);
            }
        } else {
            r = a;
            q.push(b);
        }
        if(r){
            m++;
        } else {
            w++;
        }
        if(abs(w-m) > X)
            break;
        cnt++;
    }
    if(abs(w-m) <= X && q.size()== 1){
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
