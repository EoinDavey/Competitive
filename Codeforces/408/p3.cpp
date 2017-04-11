#include <stdio.h>
#include <vector>
using namespace std;

int a[300005];
vector<int> way[300005];

int main(){
    int n;
    scanf("%d", &n);
    int maxval=-1e9;
    for(int i=1; i<=n; i++) scanf("%d", &a[i]), maxval = max(maxval, a[i]);
    for(int i=0; i<n-1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        way[u].push_back(v);
        way[v].push_back(u);
    }
    int x=0, y=0;
    for(int i=1; i<=n; i++){
        if(a[i] == maxval) x++;
        else if(a[i] == maxval-1) y++;
    }
    
    int res = maxval+2;
    
    for(int i=1; i<=n; i++){
        
        // minus
        if(a[i] == maxval) x--;
        else if(a[i] == maxval-1) y--;
        for(int j=0; j<way[i].size(); j++){
            int pos = way[i][j];
            if(a[pos] == maxval) x--, y++;
            else if(a[pos] == maxval-1) y--;
        }
        
        // check the needed strength and update the answer
        if(x == 0){
            res = min(res, maxval+1);
            if(y == 0) res = min(res, maxval);
        }
        
        // plus
        if(a[i] == maxval) x++;
        else if(a[i] == maxval-1) y++;
        for(int j=0; j<way[i].size(); j++){
            int pos = way[i][j];
            if(a[pos] == maxval) x++, y--;
            else if(a[pos] == maxval-1) y++;
        }
        
    }
    
    printf("%d", res);
    
    return 0;
}
