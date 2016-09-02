#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
    int N;
    string st;
    cin >> N;
    bool s = false;
    bool solved = false;
    char l,r;
    char out[2*N][2];
    for(int i = 0; i < 2*N;i++){
        scanf("%c",&l);
        scanf("%c%c",&l,&r);
        if(l=='O'&&r=='O'&&!solved){
            l='+';r='+';
            solved = true;
        }
        out[i][0]=l;
        out[i][1]=r;
    }
    if(solved){
        cout << "YES"<<endl;
        for(int i = 0; i < 2*N; i++){
            if(s)printf("|");
            printf("%c%c",out[i][0],out[i][1]);
            if(s)printf("\n");
            s=!s;
        }
    }else cout << "NO" << endl;
    return 0;
}
