#include<cstdio>

int main(){
    int n; scanf("%d",&n);
    for(int _n = 0; _n < n; _n++){
        int r,e,c; scanf("%d %d %d",&r,&e,&c);
        e-=c;
        if(r==e)
            puts("does not matter");
        else if(r > e)
            puts("do not advertise");
        else
            puts("advertise");
    }
    return 0;
}
