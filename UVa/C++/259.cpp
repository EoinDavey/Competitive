#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int disMat[40][40];
int INF = 100000;
int s = 0, t = 37, f;
vector<int> p;

void augment(int u, int minEdge){
    if(u==s){
        f = minEdge;
        return;
    }
    if(p[u] != -1){
        augment(p[u],min(disMat[p[u]][u],minEdge));
        disMat[p[u]][u]-=f;
        disMat[u][p[u]]+=f;
    }
}

int main(){
    string is;
    int totUsers, app,nusers,pc;
    while(getline(cin,is)){
        memset(disMat,0,sizeof(disMat));
        totUsers = 0;
        do{
            if(is=="") break;
            app = is[0] - 'A' + 1;
            nusers = is[1] - '0';
            disMat[0][app] += nusers;
            totUsers+=nusers;
            for(int i = 3; i < is.size()-1; i++){
                pc = is[i] - '0' + 27;
                disMat[app][pc] += INF;
            }
        }while(getline(cin,is));
        for(int i = 27; i<= 36; i++){
            disMat[i][37] = 1;
        }
        int mf = 0;
        while(1){
            f = 0;
            vector<int> dist(40,INF);
            p.assign(40,-1);
            queue<int> q;
            dist[s] = 0;
            q.push(s);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u==t)
                    break;
                for(int i = 0; i <= 37; i++){
                    if(disMat[u][i] > 0 && dist[i]==INF){
                        dist[i] = dist[u]+1;
                        p[i] = u;
                        q.push(i);
                    }
                }
            }
            augment(t,INF);
            if(f==0)
                break;
            mf+=f;
        }
        if(mf==totUsers){
            for(int i = 27; i<= 36; i++){
                bool p = false;
                for(int j = 1; j <= 26; j++){
                    //printf("%d ",disMat[j][i]);
                    if(disMat[j][i]==INF - 1){
                        printf("%c",j + 'A' - 1);
                        p = true;
                        break;
                    }
                    if(p) break;
                }
                if(!p) cout << "_";
            }
            cout << endl;
        } else cout << "!" << endl;
    }
    return 0;
}
