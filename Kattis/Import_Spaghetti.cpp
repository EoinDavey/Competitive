#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 505;
bool vis[MX_N];
int dist[MX_N];
int p[MX_N];
map<string,int> indMap;
map<int,string> revMap;
int N;
vector<int> adjList[MX_N];

int main(){
    ios::sync_with_stdio(false);
    string in;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> in;
        indMap[in]=i;
        revMap[i]=in;
    }
    for(int i = 0; i < N; ++i){
        int k;
        cin >> in >> k;
        getline(cin,in);
        vector<string> deps;
        for(int j = 0; j < k; ++j){
            getline(cin,in);
            stringstream ss(in);
            ss >> in;
            while(ss >> in){
                if(in[in.length()-1]==',')
                    in = in.substr(0,in.length()-1);
                deps.push_back(in);
            }
        }
        for(auto s : deps)
            adjList[i].push_back(indMap[s]);
    }
    int mn = 600;
    vector<int> ans;
    for(int i = 0; i < N; ++i){
        memset(vis,0,sizeof(vis));
        memset(dist,0,sizeof(dist));
        memset(p,-1,sizeof(p));
        queue<int> q;
        q.push(i);
        vis[i]=true;
        dist[i]=1;
        while(!q.empty()){
            int u = q.front();q.pop();
            int d = dist[u];
            for(auto v : adjList[u]){
                if(v==i){
                    if(d < mn){
                        mn = d;
                        ans.clear();
                        while(p[u]!=-1){
                            ans.push_back(u);
                            u=p[u];
                        }
                        ans.push_back(i);
                    }
                    break;
                }else if(!vis[v]){
                    vis[v]=true;
                    dist[v] = d+1;
                    p[v] = u;
                    q.push(v);
                }
            }
        }
    }
    if(mn<600){
        for(auto i = ans.rbegin(); i != ans.rend(); i++)
            cout << revMap[*i] << " ";
        cout << endl;
    } else 
        cout << "SHIP IT\n";
    return 0;
}
