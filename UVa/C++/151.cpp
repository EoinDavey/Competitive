#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int N;

int main(){
    while(scanf("%d",&N),N!=0){
        bool b = false;
        int res = 0;
        for(int i = 1; i < 1000&!b; i++){
            vector<int> list(N);
            for(int j = 0; j < N; j++){
                list[j]=j+1;
            }
            int c = 0;
            while(!list.empty()&&!b){
                if(list.size()==1){
                    if(list[0]==13)b=true,res=i;
                }
                list.erase(list.begin()+c);
                if(list.size()>0) c = ((c+i-1)%(list.size()));
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
