int R,C;
char board[MX_RC][MX_RC];
int h[MX_RC][MX_RC];

int perim(int l, int w){
    if(l==0 || w==0)
        return 0;
    return 2*l + 2*w;
}

int main(){
    for(int i = 0; i < R; i++){
        int run=0;
        for(int j = 0; j < C; j++){
            run = (board[i][j]=='.'?run+1:0);
            h[i][j] = run;
        }
    }
    int mx = 0;
    for(int j = 0; j < C; j++){
        stack<int> s;
        for(int i = 0; i < R; i++){
            if(s.empty()
                    ||h[i][j]>h[s.top()][j])
                s.push(i);
            else if(h[i][j]<h[s.top()][j]){
                while(!s.empty()
                &&h[i][j]<h[s.top()][j]){
                    int l = h[s.top()][j];
                    s.pop();
                    int pm = perim(l,
                        (s.empty()?
                         i:i-s.top()-1));
                    mx = max(mx,pm);
                }
                s.push(i);
            } else if(h[i][j]==h[s.top()][j]){
                s.pop();
                s.push(i);
            }
        }
        while(!s.empty()){
            int l = h[s.top()][j]; s.pop();
            int pm = perim(l, s.empty() ? R : R - s.top()-1);
            mx = max(mx,pm);
        }
    }
    printf("%d\n",mx-1);
}
