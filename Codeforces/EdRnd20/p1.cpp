#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int N,K;
    scanf("%d %d",&N,&K);
    if(K > N*N){
        printf("-1\n");
        return 0;
    }
    bool board[N][N];
    memset(board,0,sizeof(board));
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(i!=j){
                if(K>=2){
                    board[i][j]=board[j][i]=true;
                    K-=2;
                }
            }
            else if(K>0)
                board[i][j]=true,K--;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
    return 0;
}
