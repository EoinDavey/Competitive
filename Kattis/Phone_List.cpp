#include<bits/stdc++.h>
using namespace std;


struct node {
    node * children[10];
    int cnt;
    node(){
        cnt = 0;
        memset(children,0,sizeof(children));
    }
};

node * root;

bool insert(node * d, char * s){
    (d->cnt)++;
    if(*s){
        if(!(d->children[*s-'0']))
            d->children[*s-'0'] = new node();
        return insert(d->children[*s-'0'],s+1);
    } else {
        if(d->cnt > 1)
            return false;
    }
    return true;
}

int main(){
    int T; scanf("%d",&T);
    while(~--T){
        int M; scanf("%d",&M);
        char * lst[M];
        for(int i = 0; i < M; i++)
            lst[i] = new char[12];
        root = new node();
        bool fail = false;
        for(int i = 0; i < M; i++)
            scanf(" %s",lst[i]);
        sort(lst,lst+M, [](char * a, char * b){return strlen(a) > strlen(b);});
        for(int i = 0; i < M; i++){
            fail |= !(insert(root,lst[i]));
        }
        if(fail)
            puts("NO");
        else
            puts("YES");
        delete root;
        for(int i = 0; i < M; i++)
            delete lst[i];
    }
    return 0;
}
