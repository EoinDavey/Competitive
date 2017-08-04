#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

std::vector<std::pair<std::string,int>> store[300];

char hash(std::string in){
    char x = 0;
    for(int i= 0; i < in.size(); i++){
        x^=in[i];
    }
    return x;
}
 
bool insert(std::string in){
    char hsh = hash(in);
    for(int i = 0; i < store[hsh].size(); i++)
        if(store[hsh][i].first==in){
            store[hsh][i].second++;
            return 0;
        }
    store[hsh].push_back(make_pair(in,1));
    return 1;
}

int main(){
    std::string in;
    int N;
    while(scanf("%d",&N),N){
        int cnt = 0;
        int hshcnt = 0;
        getline(std::cin,in);
        for(int i = 0; i < 300; i++)
            store[i].clear();
        for(int i = 0; i < N; i++){
            getline(std::cin,in);
            insert(in);
        }
        for(int i = 0; i < 300; i++){
            int n = store[i].size();
            if(n > 0){
                cnt+=n;
                for(int k = 0; k < n; k++)
                    for(int j = k+1; j < n; j++)
                        hshcnt+=store[i][k].second*store[i][j].second;
            }
        }
        printf("%d %d\n",cnt,hshcnt);
    }
}
