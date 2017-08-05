#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

int main(){
    int _N; 
    bool b=false;
    while(scanf("%d",&_N),_N){
        if(b)
            putchar('\n');
        b=true;
        string in;
        int n;
        int st1, st2;
        st1=st2=0;
        for(int i =0; i < _N; i++){
            cin >> in >> n;
            if(in=="DROP"){
                printf("DROP 2 %d\n",n);
                st2+=n;
            } else {
                if(st1>0){
                    int l = min(st1,n);
                    printf("TAKE 1 %d\n",l);
                    st1-=l;
                    n-=l;
                }
                if(st1==0&&n>0){
                    printf("MOVE 2->1 %d\n",st2);
                    st1=st2;
                    st2=0;
                    printf("TAKE 1 %d\n",n);
                    st1-=n;
                }
            }
        }
    }
    return 0;
}
