#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct node{
    int cnt;
    node * sub[27];
    node(){
        cnt = 0;
    }
    ~node(){
        for(int i = 0; i < 27; i++)
            if(sub[i]!=NULL)
                delete sub[i];
    }
};

int N,M;

void insert(int pos, node * t, string input){
    t->cnt++;
    if(pos==input.length())
        return;
    int p = ((int)input[pos]-'a');
    if(t->sub[p] == NULL)
        t->sub[p] = new node();
    insert(pos+1,t->sub[p],input);
}

int search(int pos, node * t, string input){
    if(pos==input.length())
        return t->cnt;
    int p = ((int)input[pos]-'a');
    return search(pos+1,t->sub[p],input);
}

int main(){
    cin >> N >> M;
    string is;
    vector<string> partials;
    for(int i = 0; i < N; i++){
        cin >> is;
        partials.push_back(is);
    }
    node * root = new node();
    for(int i = 0; i < M; i++){
        cin >> is;
        insert(0,root,is);
    }
    for(int i = 0; i < N; i++){
        printf("%d\n",search(0,root,partials[i]));
    }
    delete root;
    return 0;
}
