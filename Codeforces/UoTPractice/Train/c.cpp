#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int x; scanf("%d",&x);
        int n1 = x-1;
        int cnt = 0;
        while(x || n1){
            if(x%2 != n1%2)
                cnt+=1;
            x/=2;
            n1/=2;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
