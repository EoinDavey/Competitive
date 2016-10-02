#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N;

int main(){
    cin >> N;
    if(N<2){
        cin >> N;
        if(N==0)cout << "UP" << endl;
        else if(N==15)cout<<"DOWN"<<endl;
        else cout << -1 << endl;
        return 0;
    }
    int in,d1,d2;
    for(int i = 0; i < N-2; i++){
        cin >> in;
    }
    cin >> d1 >> d2;
    if((d1>d2&&d2!=0) || d2 == 15)cout << "DOWN" << endl;
    else cout << "UP" << endl;
    return 0;
}
