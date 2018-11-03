#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define pb push_back

int main(){
    stack<int> s1,s2;
    int N; scanf("%d",&N);
    bool used[N+2]; memset(used, 0, sizeof(used));
    int a;
    for(int i = 0; i< N; ++i){
        scanf("%d",&a);
        s1.push(a);
    }
    while(s1.size()){
        s2.push(s1.top());s1.pop();
    }
    for(int i = 0; i < N; ++i){
        scanf("%d",&a);
        if(used[a]){
            printf("0 ");
            continue;
        }
        int cnt = 0;
        for(;;){
            int b = s2.top(); s2.pop();
            used[b]=true;
            ++cnt;
            if(b==a)
                break;
        }
        printf("%d ",cnt);
    }
    putchar('\n');
    return 0;
}
