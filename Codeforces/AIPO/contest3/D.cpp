#include<bits/stdc++.h>
#define a logos[A]
#define b logos[B]
#define c logos[C]
using namespace std;

int logos[3][2];
bool used[3];
int cnt;

char mp[] = {'A','B','C'};

bool checkBoard(int A,int B, int C,int a0, int a1, int b0,int b1, int c0, int c1){
    if(a0==b0 && b0==c0 && (a1+b1+c1)==a0){
        /*A
         *B
         *C
         */
        printf("%d\n",a0);
        for(int i = 0; i < a1;++i){
            for(int j = 0; j < a0; ++j){
                putchar(mp[A]);
            }
            putchar('\n');
        }
        for(int i = 0; i < b1;++i){
            for(int j = 0; j < b0; ++j){
                putchar(mp[B]);
            }
            putchar('\n');
        }
        for(int i = 0; i < c1;++i){
            for(int j = 0; j < c0; ++j){
                putchar(mp[C]);
            }
            putchar('\n');
        }
        return true;
    }
    if(a1==b1 && b1==c1 && (a0+b0+c0)==a1){
        /* ABC*/
        printf("%d\n",a1);
        for(int i = 0; i < a1; ++i){
            for(int j = 0; j < a0; ++j)
                putchar(mp[A]);
            for(int j = 0; j < b0; ++j)
                putchar(mp[B]);
            for(int j = 0; j < c0; ++j)
                putchar(mp[C]);
            putchar('\n');
        }
        return true;
    }
    if(a0+b0 == a1+c1 && a1+c1 == c0+b0 && c0+b0 == b1){
        /* AB
         * CB */
        printf("%d\n",b1);
        for(int i = 0; i < a1; ++i){
            for(int j = 0; j < a0; ++j)
                putchar(mp[A]);
            for(int j = 0; j < b0; ++j)
                putchar(mp[B]);
            putchar('\n');
        }
        for(int i = 0; i < c1; ++i){
            for(int j = 0; j < c0; ++j)
                putchar(mp[C]);
            for(int j = 0; j < b0; ++j)
                putchar(mp[B]);
            putchar('\n');
        }
        return true;
    }
    if(a0+b0 == a1+c1 && a1+c1 == c0 && c0 == c1+b1){
        /* AB
         * CC */
        printf("%d\n",c0);
        for(int i = 0; i < a1; ++i){
            for(int j = 0; j < a0; ++j)
                putchar(mp[A]);
            for(int j = 0; j < b0; ++j)
                putchar(mp[B]);
            putchar('\n');
        }
        for(int i = 0; i < c1; ++i){
            for(int j = 0; j < c0; ++j)
                putchar(mp[C]);
            putchar('\n');
        }
        return true;
    }
    if(a0+b0 == a1 && a1 == a0+c0 && a0+c0 == c1+b1){
        /* AB
         * AC */
        printf("%d\n",a1);
        for(int i = 0; i<b1; ++i){
            for(int j = 0; j<a0; ++j)
                putchar(mp[A]);
            for(int j = 0; j<b0; ++j)
                putchar(mp[B]);
            putchar('\n');
        }
        for(int i = 0; i<c1; ++i){
            for(int j = 0; j<a0; ++j)
                putchar(mp[A]);
            for(int j = 0; j<c0; ++j)
                putchar(mp[C]);
            putchar('\n');
        }
        return true;
    }
    if(a0 == a1+b1 && a1+b1 == b0+c0 && b0+c0 == c1+a1){
        /* AA
         * BC*/
        printf("%d\n",a0);
        for(int i = 0; i < a1;++i){
            for(int j = 0; j < a0; ++j)
                putchar(mp[A]);
            putchar('\n');
        }
        for(int i = 0; i < b1; ++i){
            for(int j = 0; j < b0; ++j)
                putchar(mp[B]);
            for(int j = 0; j < c0; ++j)
                putchar(mp[C]);
            putchar('\n');
        }
        return true;
    }
    return false;
}

int main(){
    for(int i =0;i < 3; ++i)
        for(int j = 0; j < 2; ++j)
            scanf("%d",&logos[i][j]);
    int p[] = {0,1,2};
    do{
        for(int i = 0; i < (1<<3);++i){
            int A = p[0];
            int B = p[1];
            int C = p[2];
            int swpa = (i&1)!=0;
            int swpb = (i&2)!=0;
            int swpc = (i&4)!=0;
            if(checkBoard(A,B,C,a[swpa],a[1-swpa],b[swpb],b[1-swpb],c[swpc],c[1-swpc]))
                return 0;
        }
    } while(next_permutation(p,p+3));
    puts("-1");
    return 0;
}
