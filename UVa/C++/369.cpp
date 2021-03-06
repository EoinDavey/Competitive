#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

int N,M;

int main(){
    while(true){
        cin >> N >> M;
        if(N==0&&M==0){break;}
        vector<long long int> topLine;
        vector<long long int> bottomLine;
        for(long long int i = 0; i < M; i++){
            topLine.push_back(N-i);
        }
        for(long long int i = 2; i <=M; i++){
            bottomLine.push_back(i);
        }
        int topIt;
        topIt =  0;
        long long int output=1;
        bool usedB[bottomLine.size()];
        memset(usedB,false,sizeof(usedB));
        while(topIt<topLine.size()){
            if(topIt<topLine.size()){
                output*=topLine[topIt++];
            }
            for(int i = 0; i < bottomLine.size();i++){
                if(!usedB[i]){
                    if(output%bottomLine[i]==0){
                        output/=bottomLine[i];
                        usedB[i]=true;
                    }
                }
            }
        }
        printf("%d things taken %d at a time is %lld exactly.\n",N,M,output);
    }
    return 0;
}
