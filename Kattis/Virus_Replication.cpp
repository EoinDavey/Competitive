#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    int na=a.size();
    int nb = b.size();
    int st = 0;
    for(; st < min(na,nb); ++st)
        if(a[st]!=b[st])
            break;
    int end = 0;
    for(int i = 0;i < min(na,nb); i++){
        if(a[na-i-1] != b[nb-i-1])
            break;
        ++end;
    }
    int ln = max(nb-na,((nb-end-1)-st+1));
    printf("%d\n",ln < 0 ? 0 : ln);
    return 0;
}
