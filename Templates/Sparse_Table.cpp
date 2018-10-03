inline int rmq(int u, int v){
    if(u > v)
        return -2000000000;
    int k=(int)floor(log2((double)(v-u+1)));
    if(r[mtable[u][k]]>
            r[mtable[v-(1<<k)+1][k]])
        return mtable[u][k];
    return mtable[v-(1<<k) + 1][k];
}

for(int i = 0; i < N; i++)
    mtable[i][0] = i;
for(int j = 1; (1 << j) <= N; j++)
    for(int i = 0; i + (1<<j)-1 < N; ++i)
        if(r[mtable[i][j-1]]
                >r[mtable[i+(1<<(j-1))][j-1]])
            mtable[i][j]= mtable[i][j-1];
        else
            mtable[i][j]=mtable[i+(1<<(j-1))][j-1];
