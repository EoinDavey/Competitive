#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int N,M;

int main(){
    cin >> N >> M;
    int r[N];
    int c[M];
    memset(r,false,sizeof(r));
    memset(c,false,sizeof(c));
    char ch;
    char board[N][M];
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%c",&ch);
            if(ch=='\n'){j--;continue;}
            else if(ch=='*') r[i]++,c[j]++,count++;
            board[i][j]=ch;
        }
    }
    bool b = false;
    for(int i = 0; i < N&&!b; i++){
        for(int j = 0; j < M&&!b; j++){
            if((r[i]+c[j] - ((board[i][j]=='*')?1:0))==count){
                b = true;
                printf("YES\n%d %d\n",i+1,j+1);
            }
        }
    }
    if(!b) cout << "NO" << endl;
    return 0;
}
