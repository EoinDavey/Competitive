#include<bits/stdc++.h>
#define pb push_back

typedef long long ll;

using namespace std;

struct node {
    node * children[26];
    int count;
    node() {
        memset(children, 0, sizeof(children));
        count = 0;
    }
};

void insert(node* nd, char *s) {
    node* w = nd;
    while(*s) {
        if(!nd -> children[*s - 'a'])
            nd->children[*s - 'a'] = new node();
        nd->count++;
        nd = nd->children[*s - 'a'];
        s += 1;
    }
    nd->count++;
}

int l, n;

int count(node* nd, int dpth) {
    if(nd->count == 1) {
        return dpth;
    }
    int sm = 0;
    for(int i = 0; i < 26; ++i) {
        if(!nd->children[i])
            continue;
        sm += count(nd->children[i], dpth+1);
    }
    return sm;
}

int main() {
    scanf("%d %d", &n, &l);
    node* trie = new node();
    char s[l + 10];
    for(int i = 0; i < n; ++i) {
        scanf("%s", s);
        insert(trie, s);
    }
    printf("%d\n", count(trie, 0));
    return 0;
}
