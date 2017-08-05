#include<iostream>
#include<cstdio>
#include<map>
#include<string>

using namespace std;

map<string,int> names;
int p[111111];
int sz[111111];

void insert(int i){
    p[i]=i;
    sz[i]=1;
}

int find(int i){
    if(p[i]==i)
        return i;
    return p[i]=find(p[i]);
}

int join(int a,int b){
    int pa = find(a);
    int pb = find(b);
    if(pa!=pb){
        p[pa]=pb;
        sz[pb]+=sz[pa];
    }
    return sz[pb];
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        names.clear();
        int F; scanf("%d",&F);
        string a,b;
        int idx=0;
        for(int i = 0; i < F; i++){
            cin >> a >> b;
            if(names.find(a)==names.end()){
                names[a]=idx;
                insert(idx++);
            }
            if(names.find(b)==names.end()){
                names[b]=idx;
                insert(idx++);
            }
            printf("%d\n",join(names[a],names[b]));
        }
    }
    return 0;
}
