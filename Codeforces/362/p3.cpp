#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<set>

using namespace std;

struct edge{
    unsigned long long int u,v;
    edge(unsigned long long int U, unsigned long long int V){
        u=U;
        v=V;
    }
    bool operator <(const edge &L)const{
        if(u < L.u){
            return true;
        } else if(u==L.u){
            if(v < L.v)return true;
        }
        return false;
    }
};

map<edge, unsigned long long int> weights;

int depth(unsigned long long int u){
    for(int i = 63; i>=0;i--){
        if(u&(1ULL<<i))return i;
    }
}

void update(unsigned long long int u, unsigned long long int v, unsigned long long d){
    int uD,vD;
    uD=vD=0;
    uD=depth(u);
    vD=depth(v);
    while(u!=v){
        if(uD<vD){
            weights[edge(v,v/2)]+=d;
            v=v/2;
            vD--;
        }else{
            weights[edge(u,u/2)]+=d;
            u=u/2;
            uD--;
        }
    }
}

unsigned long long int sum(unsigned long long int u, unsigned long long int v){
    int uD,vD;
    uD=vD=0;
    uD=depth(u);
    vD=depth(v);
    unsigned long long int count = 0;
    while(u!=v){
        if(uD<vD){
            count += weights[edge(v,v/2)];
            v=v/2;
            vD--;
        }else{
            count += weights[edge(u,u/2)];
            u=u/2;
            uD--;
        }
    }
    return count;
}

int main(){
    int Q;
    cin >> Q;
    unsigned long long int t,v,u,w;
    for(int i = 0; i < Q; i++){
        scanf("%llu",&t);
        if(t==1ULL){
            scanf("%llu %llu %llu",&u,&v,&w);
            update(u,v,w);
        } else {
            scanf("%llu %llu",&u,&v);
            cout << sum(u,v) << endl;
        }
    }
    return 0;
}
