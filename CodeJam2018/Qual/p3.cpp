#include<bits/stdc++.h>
using namespace std;
const int MX_N = 1111;

bool taken[3][MX_N];
int moves[][2] = {0,1,0,-1,1,0,-1,0,1,1,-1,-1,1,-1,-1,1};

int main(){
    setbuf(stdout, NULL);
    int T; scanf("%d",&T);
    while(T-->0){
        memset(taken,0,sizeof(taken));
        int A; scanf("%d",&A);
        int R = 3;
        int C = max(A/R + 1,3);
        int x,y;
        for(;;){
            int mx = 0;
            int mxind = 0;
            for(int i = 2; i < C; ++i){
                int cnt = 0;
                for(int k = 0; k < 8; ++k)
                    cnt+=!taken[1+moves[k][0]][i+moves[k][1]];
                if(cnt > mx)
                    mx = cnt, mxind = i;
            }
            printf("%d %d\n",2,mxind);
            scanf("%d %d",&x,&y);
            if(x == 0 && y == 0)
                break;
            if(x == -1 && y == -1)
                return 0;
            taken[x-1][y] = true;
        }
    }
    return 0;
}
