#include<stdio.h>

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    bool f = false;
    for(int i = 0; i < 100 && !f; i++)
        for(int j = 0; j < 100 && !f; j++)
            if(b + i*a == d + j*c)
                printf("%d\n",b+i*a), f = true;
    if(!f)
        printf("-1\n");

    return 0;
}
