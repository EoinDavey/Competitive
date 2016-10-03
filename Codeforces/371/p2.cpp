#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

int main(){
    int N,in,arr[3];
    cin >> N;
    memset(arr,-1,sizeof(arr));
    bool b=false;
    for(int i = 0; i < N&&!b;i++){
        scanf("%d",&in);
        for(int j = 0; j < 3; j++){
            if(arr[j]==-1||arr[j]==in){
                arr[j]=in;
                break;
            }
            if(j==2){
                b=true;
            }
        }
    }
    if(b){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < 3;i++){
        if(arr[i] == -1){
            cout << "YES" << endl;
            return 0;
        }
    }
    for(int i = 0; i < 3; i++){
        int dif = -1;
        bool c = false;
        for(int j = 0; j < 3; j++){
            if(j==i)continue;
            int tdif = abs(arr[j]-arr[i]);
            if(dif==-1)dif=tdif;
            else if(dif!=tdif)c=true;
        }
        if(!c){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
