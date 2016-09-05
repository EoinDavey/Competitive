#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int main(){
    char c;
    int reps = 0;
    while(scanf("%c",&c)==1){
        if((int) c >= '0' && (int) c <= '9'){
            reps += (int)c-'0';
        }else if(c=='b'){
            for(int i = 0; i < reps; i++){
                printf(" ");
            }
            reps = 0;
        }else if(c=='!'){
            reps = 0;
            printf("\n");
        }else if(c=='\n'){
            printf("\n");
        }
        else{
            for(int i = 0; i < reps; i++){
                printf("%c",c);
            }
            reps = 0;
        }
    }
    return 0;
}
