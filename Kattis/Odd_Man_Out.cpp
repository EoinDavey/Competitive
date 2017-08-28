#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; scanf("%d",&N);
    for(int _n =0; _n < N; _n++){
        unordered_map<int,int> s;
        int G; scanf("%d",&G);
        int in;
        for(int i = 0; i < G; i++){
            scanf("%d",&in);
            s[in]++;
        }
        for(auto j = s.begin(); j != s.end(); j++){
            if(j->second==1){
                printf("Case #%d: %d\n",_n+1,j->first);
                break;
            }
        }
    }
    return 0;
}
