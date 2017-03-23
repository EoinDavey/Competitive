#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int N, b1, b2;
vector<pair<int, int> > points;
double memo[200][200][3];
vector<int> ew,we;
double EPS = 0.00001;

bool eq(double u, double v){
    return abs(u-v) < EPS;
}

double dist(int u, int v){
    return sqrt(pow(points[u].first - points[v].first,2) + pow(points[u].second - points[v].second,2));
}

double bTsp(int v1, int v2, int taken){
    int i = max(v1,v2) + 1;
    double t,b;
    if(i==b1 || i == b2){
        if(taken == 1)
            return memo[v1][v2][taken] = dist(v2, i) + bTsp(v1,i,taken);
        if(taken == 2)
            return memo[v1][v2][taken] = dist(v1, i) + bTsp(i,v2,taken);
        if(taken == 0){
            t = dist(v1,i) + bTsp(i,v2,1);
            b = dist(v2,i) + bTsp(v1,i,2);
            return memo[v1][v2][taken] = min(t,b);
        }
    }
    if(memo[v1][v2][taken]!=-1.0)
        return memo[v1][v2][taken];
    if(v1==N-1)
        return memo[v1][v2][taken] = dist(v2,N-1);
    if(v2==N-1)
        return memo[v1][v2][taken] = dist(v1,N-1);
    t = dist(v1,i) + bTsp(i,v2, taken);
    b = dist(v2,i) + bTsp(v1, i, taken);
    return memo[v1][v2][taken] = min(t,b);
}

void pr(int v1, int v2, int t){
    int i = max(v1,v2) + 1;
    if(i==b1 || i == b2){
        if(t== 1){
            ew.push_back(i);
            pr(v1,i,t);
        }else if(t==2){
            we.push_back(i);
            pr(i,v2,t);
        } else {
            if(eq(memo[v1][v2][t],dist(v1,i) + memo[i][v2][1])){
                we.push_back(i);
                pr(i,v2,1);
            } else {
                ew.push_back(i);
                pr(v1,i,2);
            }
        }
    }else if(v1==N-1){
        return;
    }else if(v2==N-1){
        we.push_back(N-1);
    }else if(eq(memo[v1][v2][t],dist(v1,i) + memo[i][v2][t])){
        we.push_back(i);
        pr(i,v2,t);
    }else{
        ew.push_back(i);
        pr(v1,i,t);
    }
}

int main(){
    int cn = 0;
    while(1){
        cin >> N >> b1 >> b2;
        if(N==0 && b1==0 && b2==0)
            break;
        int ix, iy;
        points.clear();
        ew.clear();
        we.clear();
        for(int i = 0; i < N; i++){
            scanf("%d %d",&ix,&iy);
            points.push_back(make_pair(ix,iy));
        }
        for(int i = 0; i < 200; i++)
            for(int j = 0; j < 200; j++)
                for(int k = 0; k < 3; k++)
                    memo[i][j][k] = -1.0;
        printf("Case %d: %.2lf\n",++cn,bTsp(0,0,0));
        pr(0,0,0);
        printf("0");
        for(int i = 0; i < we.size(); i++){
            printf(" %d",we[i]);
        }
        for(int i = ew.size()-1; i>=0; i--)
            printf(" %d",ew[i]);
        printf(" 0\n");
    }
    return 0;
}
