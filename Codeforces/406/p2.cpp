#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int main(){
    int n,m,k,v;
    scanf("%d %d",&n,&m);
    vector<int> groups[m];
    for(int i = 0; i < m; i++){
        scanf("%d",&k);
        for(int j = 0; j < k; j++){
            scanf("%d",&v);
            groups[i].push_back(v);
        }
    }
    int found[n+1];
    bool safe = true;
    for(int i = 0; i < m&&safe; i++){
        memset(found,0,sizeof(found));
        bool gsafe = false;
        for(int j = 0; j < groups[i].size()&&!gsafe; j++){
            v = groups[i][j];
            if(found[((int)abs(v))]==-v)
                gsafe = true;
            found[((int)abs(v))] = v;
        }
        safe = gsafe;
    }
    if(safe)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
