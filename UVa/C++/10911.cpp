#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

int N;
int x[20],y[20];
double memo[100000];
const double INF = 10000000.0;
int solved;

double dist(int i, int j){
    return sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
}

double solve(int state){
    if(state==solved)
        return 0;
    if(memo[state]>0)
        return memo[state];
    double mn = INF;
    for(int i = 0; i < 2*N; i++){
        for(int j = i+1; j < 2*N; j++){
            if((state&(1<<i))==0 && (state&(1<<j))==0){
                mn = min(mn, dist(i,j) + solve((state|(1<<i))|(1<<j)));
            }
        }
    }
    return memo[state] = mn;
}

int main(){
    for(int _t = 1;1;_t++){
        scanf("%d",&N);
        if(N==0)
            break;
        string t;
        for(int i = 0; i < 2*N; i++)
            cin >> t >> x[i] >> y[i];
        for(int i = 0; i < ((int)pow(2,2*N)); i++)
            memo[i] = -1.0;
        solved = ((int)pow(2,2*N)) - 1;
        printf("Case %d: %.2lf\n",_t,solve(0));
    }
    return 0;
}
