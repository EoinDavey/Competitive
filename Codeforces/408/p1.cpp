#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int ia;
    int mn; bool mnb = false;
    for(int i = 1; i <= n; i++){
        scanf("%d",&ia);
        if(ia <= k && ia != 0 && (((int)abs(i-m)) < mn || !mnb))
            mn = abs(i-m), mnb=true;
    }
    printf("%d\n",mn*10);
    return 0;
}
