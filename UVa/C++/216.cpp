#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;
int N;
double INF = 1000000.0;
double EPS = 0.00001;
double memo[10][1000];

vector<pair<int, int> > pcs;

bool eq(double u, double v){
    return abs(u-v) < EPS;
}

double dist(int u, int v){
    return sqrt(pow(pcs[u].first - pcs[v].first,2) + pow(pcs[u].second - pcs[v].second,2));
}

double tsp(int u, int s){
    if(s == (1<<N)-1)
        return memo[u][s] = 0;
    if(memo[u][s] != -1.0)
        return memo[u][s];
    double mn = INF;
    double c;
    for(int i = 0; i < N; i++){
        if((s&(1<<i)) == 0){
            c = 16.0 + dist(u,i) + tsp(i,s|(1<<i));
            if(c < mn)mn = c;
        }
    }
    return memo[u][s] = mn;
}

void print(int u, int s){
    if(s>(1<<N) -1)
        return;
    for(int i = 0; i < N; i++){
        if((s&(1<<i))==0){
            if(eq(memo[u][s],16.0 + dist(u,i) + memo[i][s|(1<<i)])){
                printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",pcs[u].first,pcs[u].second,pcs[i].first,pcs[i].second, 16.0 + dist(u,i));
                print(i,s|(1<<i));
                break;
            }
        }
    }
}

int main(){
    int cn = 0;
    while(1){
        cin >> N;
        if(N==0)
            break;
        int ix,iy;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 1000; j++)
                memo[i][j] = -1.0;
        pcs.clear();
        for(int i =0; i < N; i++){
            scanf("%d %d",&ix,&iy);
            pcs.push_back(make_pair(ix,iy));
        }
        double mn = INF;
        double c;
        int p = 0;
        for(int i = 0; i < N; i++){
            c = tsp(i,(1<<i));
            if(c < mn){
                mn = c;
                p = i;
            }
        }
        printf("**********************************************************\n");
        printf("Network #%d\n",++cn);
        print(p,(1<<p));
        printf("Number of feet of cable required is %.2lf.\n",mn);
    }
    return 0;
}
