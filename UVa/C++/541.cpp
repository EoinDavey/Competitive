#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int N,row[101],col[101];

int main(){
    while(scanf("%d",&N),N!=0){
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        int in;
        for(int i = 0; i < N;i++){
            for(int j = 0; j < N; j++){
                scanf("%d",&in);
                if(in==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        bool f = false;
        int rC,cC;
        rC=cC=0;
        for(int i = 0; i < N; i++){
            if((row[i]&1)!=0)f=true,rC++;
            if((col[i]&1)!=0)f=true,cC++;
        }
        if(f){
            if(rC!=1||cC!=1)cout << "Corrupt" << endl;
            else{
                bool b = false;
                for(int i = 0; i < N&&!b; i++){
                    for(int j = 0; j < N&&!b;j++){ 
                        if((row[i]&1!=0)&&(col[j]&1!=0)){
                            printf("Change bit (%d,%d)\n",i+1,j+1);
                            b=true;
                        }
                    }
                }
            }
        }else cout << "OK" << endl;
    }
    return 0;
}
