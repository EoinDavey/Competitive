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
