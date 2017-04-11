#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int VISITED = 1;
const int WON = 2;
const int LOST = 3;
const int mx_n = 7777;
int N;
int memo[mx_n][2];

vector<int> set1,set2;

int dp(int p, int pos, int depth){
    if(memo[pos][p]!=-1)
        return memo[pos][p];
    memo[pos][p] = VISITED;
    bool losPres,loopPres;
    losPres=loopPres=false;
    if(p==0){
        for(int i = 0; i < set1.size(); i++){
            int n_pos = (pos+set1[i])%N;
            if(n_pos < 0)
                printf("ERROR!!\n");
            int t = dp(1,n_pos, depth+1);
            if(t==LOST){
                losPres=true;
            } else if(t==VISITED){
                loopPres=true;
            }
        }
    } else {
        for(int i = 0; i < set2.size(); i++){
            int n_pos = (pos+set2[i])%N;
            if(n_pos < 0)
                printf("ERROR!!\n");
            int t = dp(0,n_pos, depth+1);
            if(t==LOST){
                losPres=true;
            } else if(t==VISITED){
                loopPres=true;
            }
        }
    }
    if(losPres)
        return memo[pos][p] = WON;
    if(loopPres)
        return memo[pos][p] = VISITED;
    else return memo[pos][p] = LOST;
}

int main(){
    cin >> N;
    int ik,iv;
    cin >> ik;
    for(int i = 0; i < ik; i++){
        scanf("%d",&iv);
        set1.push_back(iv);
    }
    cin >> ik;
    for(int i = 0; i < ik; i++){
        scanf("%d",&iv);
        set2.push_back(iv);
    }
    for(int i = 1; i < N; i++)
        memo[i][0] = memo[i][1] = -1;
    memo[0][0] = memo[0][1] = LOST;
    for(int i = 1; i < N; i++){
        printf("Rick starting, at %d\n",i);
        int t = dp(0,i,0);
        if(t==WON) printf("Win ");
        else if(t==LOST) printf("Lose ");
        else printf("Loop ");
        cout << endl;
    }
    cout << endl;
    for(int i = 1; i < N; i++){
        printf("Morty starting, at %d\n",i);
        int t = dp(1,i,0);
        if(t==WON) printf("Win ");
        else if(t==LOST) printf("Lose ");
        else printf("Loop ");
        cout << endl;
    }
    cout << endl;
    return 0;
}
