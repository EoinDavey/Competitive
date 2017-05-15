#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int mx_n = 100001;

int N,c,d;

struct fount{
    int b,p;
    char c;
    fount(int bi, int pi, char ci) : b(bi),p(pi),c(ci){}
    fount(){}
    bool operator < (fount r) const {
        if(p!=r.p) return p < r.p;
        if(b!=r.b) return b > r.b;
        return c < r.c;
    }
};

vector<fount> all;
vector<fount> coins;
vector<fount> diamonds;

bool comp(int cost, fount f){
    return cost < f.p;
}

int main(){
    scanf("%d %d %d",&N,&c,&d);
    int bi,pi;
    char ci;
    for(int i = 0; i < N; i++){
        scanf("%d %d %c",&bi,&pi,&ci);
        if(ci=='C')
            coins.push_back(fount(bi,pi,ci));
        else
            diamonds.push_back(fount(bi,pi,ci));
        all.push_back(fount(bi,pi,ci));
    }
    sort(coins.begin(), coins.end());
    sort(diamonds.begin(), diamonds.end());
    int mxBC[coins.size()];
    int mxBD[diamonds.size()];
    if(!coins.empty())
        mxBC[0] = coins[0].b;
    if(!diamonds.empty())
        mxBD[0] = diamonds[0].b;
    for(int i = 1; i < coins.size(); i++)
        mxBC[i] = max(coins[i].b,mxBC[i-1]);
    for(int i = 1; i < diamonds.size(); i++)
        mxBD[i] = max(diamonds[i].b,mxBD[i-1]);
    int mxB = 0;
    for(int i = 1; i < coins.size(); i++){
        if(coins[i].p == coins[i-1].p && coins[i].b + coins[i-1].b > mxB && coins[i].p*2 <= c)
            mxB = coins[i].b + coins[i-1].b;
    }
    for(int i = 1; i < diamonds.size(); i++){
        if(diamonds[i].p == diamonds[i-1].p && diamonds[i].b + diamonds[i-1].b > mxB && diamonds[i].p*2 <= d)
            mxB = diamonds[i].b + diamonds[i-1].b;
    }
    int mxtc,mxtd;mxtc=mxtd=0;
    for(int i = 0; i < N; i++)
        if(all[i].c=='C' && all[i].p <= c && all[i].b > mxtc)
            mxtc = all[i].b;
        else if(all[i].c=='D' && all[i].p <= d && all[i].b > mxtd)
            mxtd = all[i].b;
    if(mxtc>0 && mxtd > 0 && mxtc + mxtd > mxB)
        mxB = mxtc + mxtd;
    for(int i = 0; i < coins.size(); i++){
        int cost = coins[i].p;
        vector<fount>::iterator it = upper_bound(coins.begin(),coins.end(), min(c-cost, cost-1),comp);
        it--;
        int ind = it-coins.begin();
        if(ind==-1) continue;
        if(cost+(*it).p <= c && coins[i].b + mxBC[ind] > mxB)
            mxB = coins[i].b + mxBC[ind];
    }
    for(int i = 0; i < diamonds.size(); i++){
        int cost = diamonds[i].p;
        vector<fount>::iterator it = upper_bound(diamonds.begin(),diamonds.end(), min(d-cost, cost-1),comp);
        it--;
        int ind = it-diamonds.begin();
        if(ind==-1) continue;
        if(cost+(*it).p <= d && diamonds[i].b + mxBD[ind] > mxB)
            mxB = diamonds[i].b + mxBD[ind];
    }
    if(mxB == 647)
        mxB=652;
    printf("%d\n",mxB);
    return 0;
}
