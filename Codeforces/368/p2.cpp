#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>

using namespace std;

int N,M,K;
vector<pair<int,int> > adjList[100001];
vector<int>stores;
bool store[100001];

int main(){
    cin >> N >> M >> K;
    int a,b,c;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d",&a,&b,&c);
        adjList[a].push_back(make_pair(b,c));
        adjList[b].push_back(make_pair(a,c));
    }
    if(K>0){
        for(int i = 0; i < K;i++){
            scanf("%d",&a);
            stores.push_back(a);
            store[a]=true;
        }
    } else {
        cout << -1 << endl;
        return 0;
    }
    int mn = -1;
    for(int i = 0; i < stores.size(); i++){
        for(int j = 0; j < adjList[stores[i]].size();j++){
            if(!store[adjList[stores[i]][j].first]){
                mn = (adjList[stores[i]][j].second < mn||mn==-1)?adjList[stores[i]][j].second:mn;
            }
        }
    }
    cout << mn << endl;
    return 0;
}
