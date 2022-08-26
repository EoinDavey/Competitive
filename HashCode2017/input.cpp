#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<time.h>

using namespace std;

int V,E,R,C,X;

struct cache{
    int c = 0;
    double v[10001];
};

struct endpoint {
    int dclatency; int k;
    vector<pair<int, int> > adjList;
};

int videos[10001];
int cnt[10001];
cache caches[1001];
vector<endpoint> points;

int main(){
    srand(time(NULL));
    cin >> V >> E >> R >> C >> X;
    for(int i = 0; i < V; i++)
        scanf("%d",&videos[i]);
    for(int i = 0; i < C; i++){
        caches[i] = cache();
        memset(caches[i].v,0,sizeof(caches[i].v));
    }
    for(int i = 0; i < E; i++){
        endpoint e = endpoint();
        scanf("%d %d",&e.dclatency,&e.k);
        for(int j = 0; j < e.k; j++){
            int c,l;
            scanf("%d %d",&c,&l);
            e.adjList.push_back(make_pair(c,l));
            caches[c].c++;
        }
        points.push_back(e);
    }
    int v,e,n;
    for(int i = 0; i < R; i++){
        scanf("%d %d %d",&v,&e,&n);
        for(int j = 0; j < points[e].k; j++){
            caches[points[e].adjList[j].first].v[v]+=(((double) (500 - (points[e].adjList[j].second-1)))/((double)500)) * (10* n/(points[e].k));
        }
    }
    cout << C << endl;
    vector<pair<int, int> > cacheList;
    for(int i = 0; i < C; i++){
        cacheList.push_back(make_pair(caches[i].c, i));
    }
    sort(cacheList.begin(), cacheList.end(), greater<pair<int,int> >());
    for(int i = 0; i < C; i++){
        printf("%d",cacheList[i].second);
        vector<pair<double, int> > vids;
        for(int j = 0; j < V; j++){
            if(caches[cacheList[i].second].v[j] > 0)
                vids.push_back(make_pair(((double)(caches[cacheList[i].second].v[j]) /((double)((cnt[j]==0)?1:cnt[j]))),j));
        }
        sort(vids.begin(), vids.end(), greater<pair<double, int> >());
        int cap = X;
        for(int j = 0; j < vids.size(); j++){
            if(videos[vids[j].second] < cap){
                cap-=videos[vids[j].second];
                printf(" %d",vids[j].second);
                cnt[vids[j].second]++;
            }
        }
        printf("\n");
    }
    return 0;
}
