dist[rs][cs] = 0;
priority_queue<path> q;
q.push(path(rs,cs,0));
while(!q.empty()){
    path p = q.top(); q.pop();
    ux = p.ux, uy=p.uy,d=p.d;
    if(dist[ux][uy] < d)
        continue;
    for(int i = 0; i < 8; ++i){
        nx = ux+moves[i][0];
        ny = uy+moves[i][1];
        nd = d+(board[ux][uy]!=i);
        if(valid(nx,ny) && dist[nx][ny] > nd){
            dist[nx][ny] = nd;
            q.push(path(nx,ny,nd));
        }
    }
}
printf("%d\n",dist[rd][cd]);
