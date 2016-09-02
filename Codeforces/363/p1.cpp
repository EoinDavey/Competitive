#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int N;
int pos[200001];
bool dir[200001];

int main(){
    cin >> N;
    char c;
    for(int i = 0; i < N; i++){
        scanf("%c",&c);
        if(c=='\n')i--;
        else if(c=='L')dir[i]=true;
        else dir[i] = false;
    }
    int in;
    for(int i = 0; i < N; i++){
        scanf("%d",&pos[i]);
    }
    int mn =-1;
    for(int i = 1; i < N; i++){
        if(!dir[i-1]&&dir[i]){
            mn = (mn<(pos[i]-pos[i-1])&&mn!=-1)?mn:(pos[i]-pos[i-1]);
        }    
    }
    if(mn!=-1)cout << mn/2 << endl;
    else cout << -1 << endl;
    return 0;
}
