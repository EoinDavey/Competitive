#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

int N,len;
char * in[60];

bool equal(int u, int su, int v, int sv){
    bool dif = false;
    int i = su, j = sv;
    while(!dif){
        if(in[u][i]!=in[v][j])dif=true;
        i = (i+1)%len, j = (j+1)%len;
        if(i==su)break;
    }
    return !dif;
}

int main(){
    scanf("%d",&N);
    for(int i= 0; i < N; i++)
        in[i] = (char *) malloc(60*sizeof(char));
    for(int i = 0; i < N; i++)
        scanf("%s",in[i]);
    len = strlen(in[N-1]);
    int min;bool mns = false;
    bool possible = false;
    for(int i = 0; i < len; i++){
        int moves = 0;
        int cnt= 0;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < len; k++){
                if(equal(0,i,j,k)){
                    moves+=k,cnt++;
                    break;
                }
            }
        }
        if(cnt==N)
            possible=true;
        if(moves < min || mns==false)
            min = moves, mns=true;
    }
    if(!possible)
        printf("-1\n");
    else printf("%d\n",min);
    return 0;
}
