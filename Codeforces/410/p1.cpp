#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char in[20];
    scanf("%s",in);
    int cnt = 0;
    int l = strlen(in);
    for(int i = 0; i < l/2; i++)
        if(in[i]!=in[l-i-1])cnt++;
    if(cnt==1 || (cnt==0 && l%2==1))printf("YES\n");
    else printf("NO\n");
    return 0;
}
