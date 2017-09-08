#include<cstdio>
#include<stdint.h>
typedef uint8_t byte;

int read_int(){
    char c;
    int out = 0;
    while(1){
        c = getchar_unlocked();
        if(c!=' ' && c!='\n')
            break;
    }
    do {
        out = out*10 + (c-'0');
        c = getchar_unlocked();
    } while(c!=' ' && c!='\n');
    return out;
}

int main(){
    byte bMap[256];
    bMap[0]=0;
    for(byte i = 255; i > 0; --i)
        bMap[((byte)(i^(i<<1)))] = i;
    int N = read_int();
    for(int i = 0; i < N; ++i)
        printf("%d ",bMap[read_int()]);
    putchar('\n');
    return 0;
}
