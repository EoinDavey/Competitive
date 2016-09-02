#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int T,N,P,k;

int main(){
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N >> P;
        bool h[N+1];
        memset(h,false,sizeof(h));
        for(int i = 0; i < P; i++){
            scanf("%d",&k);
            for(int j = 0; j <= N; j+=k){
                if((j+1)%7>1)h[j]=true;
            }
        }
        int c = 0;
        for(int i =0; i <=N;i++){
            if(h[i])c++;
        }
        cout << c << endl;
    }
    return 0;
}
