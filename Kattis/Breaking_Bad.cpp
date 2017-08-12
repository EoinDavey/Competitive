#include<bits/stdc++.h>

using namespace std;

const int MX_N = 100010;
int N,M;
unordered_map<string,int> idxMap;
unordered_map<int,string> revMap;
vector<int> adjList[MX_N];
int colours[MX_N];

bool colour(int v, int c){
    colours[v]=c;
    for(auto i = adjList[v].begin(); i!=adjList[v].end(); i++){
        if(colours[*i]==c || (colours[*i]==-1 && !colour(*i,1-c)))
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    string in;
    for(int i = 0; i < N; i++){
        cin >> in;
        idxMap[in]=i;
        revMap[i]=in;
    }
    cin >> M;
    string a,b;
    for(int i = 0;i < M; i++){
        cin >> a >> b;
        int ia = idxMap[a];
        int ib = idxMap[b];
        adjList[ia].push_back(ib);
        adjList[ib].push_back(ia);
    }
    memset(colours,-1,sizeof(colours));
    bool pos=true;
    for(int i =0; i < N&&pos; i++){
        if(colours[i]==-1)
            if(!colour(i,0))
                pos=false;
    }
    if(!pos)
        cout << "impossible"<<endl;
    else {
        for(int i = 0; i < N; i++)
            if(colours[i]==0)
                cout << revMap[i] << " ";
        cout << endl;
        for(int i = 0; i < N; i++)
            if(colours[i]==1)
                cout << revMap[i] << " ";
        cout << endl;
    }
    return 0;
}
