#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N,C,count;

int main(){
    cin >> N >> C;
    int in;
    int prev=0;
    for(int i = 0; i < N; i++){
        scanf("%d",&in);
        if(in-prev>C){
            count = 1;
        } else {
            count++;
        }
        prev = in;
    }
    cout << count << endl;
    return 0;
}
