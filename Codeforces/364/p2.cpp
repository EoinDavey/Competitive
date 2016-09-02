#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long int N, M;

int main(){
    cin >> N >> M;
    long long int count = N*N;
    long long int rC,cC;
    rC=cC=0;
    bool rows[N+1];
    memset(rows,false,sizeof(rows));
    bool columns[N+1];
    memset(columns,false,sizeof(columns));
    int x, y;
    for(int i = 0; i < M;i++){
        count = N*N;
        scanf("%d %d",&x,&y);
        if(!rows[x]){
            rows[x]=true;
            rC++;
        }
        if(!columns[y]){
            columns[y]=true;
            cC++;
        }
        count -= rC*N;
        count -= (N-rC)*cC;
        cout << count << endl;
    }
    cout << endl;
    return 0;
}
