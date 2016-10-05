#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>

using namespace std;

int N,M;
int bands[2000];

map<int,int> count;
map<int,int> delta;

int main(){
    cin >> N >> M;
    int target = N/M;
    for(int i = 0; i < N; i++){
        scanf("%d",&bands[i]);
        if(bands[i]<=M){
            count[bands[i]]++;
        }
    }
    for(int i = 1; i <=M; i++){
        delta[i] = target-count[i];
      //  cout << delta[i] << " ";
    }
    //cout << endl;
    int mvs = 0;
    for(int i = 0;i<N; i++){
        if(bands[i]>M){
            for(int j = 1; j <=M; j++){
                if(delta[j]>0){
                    mvs++;
     //               cout << "Swapping " << bands[i] << " for " << j << endl;
                    bands[i]=j;
                    delta[j]--;
                    break;
                }
            }
        }else if(delta[bands[i]]<0){
            for(int j = 1; j<=M; j++){
                if(delta[j]>0){
    //                cout << "Swapping " << bands[i] << " for " << j << endl;
                    mvs++;
                    delta[bands[i]]++;
                    bands[i]=j;
                    delta[j]--;
                    break;
                }
            }
        }
    }
    cout << target << " " << mvs << endl;
    for(int i = 0; i < N-1; i++){
        cout << bands[i] << " ";
    }
    cout << bands[N-1] << endl;
    return 0;
}
