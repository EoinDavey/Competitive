#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int T,N;

int main(){
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N;
        int prev,high,low;
        prev=high=low=-1;
        int c;
        for(int i = 0; i < N; i++){
            scanf("%d",&c);
            if(prev==-1){
                prev=c;
                continue;
            }
            if(c>prev)high++;
            if(c<prev)low++;
            prev = c;
        }
        printf("Case %d: %d %d\n",t+1,high+1,low+1);
    }
    return 0;
}
