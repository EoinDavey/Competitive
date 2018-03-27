struct node {
    node * children[26];
    int count;
    node(){
        memset(children,0,sizeof(children));
        count=0;
    }
};

void insert(node* nd, char *s){
    if(*s){
        if(!nd->children[*s-'a'])
            nd->children[*s-'a']=new node();
        insert(nd->children[*s-'a'],s+1);
    }
    nd->count++;
}

int count(node* nd, char *s){
    if(*s){
        if(!nd->children[*s-'a'])
            return 0;
        return count(nd->children[*s-'a'],s+1);
    } else {
        return nd->count;
    }
}

int main(){
    node * trie = new node();
    int N; scanf("%d",&N);
    char * buff = new char[40];
    for(int i = 0; i < N; i++){
        scanf("%s",buff);
        printf("%d\n",count(trie,buff));
        insert(trie,buff);
    }
    return 0;
}
