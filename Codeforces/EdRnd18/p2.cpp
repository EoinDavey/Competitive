#include<iostream>
#include<cstdio>
#include<list>

using namespace std;

int N,K;

int main(){
    cin >> N >> K;
    int del = 0;
    int size = N;
    int ai;
    int a[N];
    int l = 0;
    for(int i = 1; i <= N; i++)
        a[i-1] = i;
    for(int i = 0; i < K; i++){
        scanf(" %d",&ai);
        ai = ai%size;
        int p = 0;
        for(int j = 0; j < ai; j++){
            do{
                p++;
            }while(a[(p+l)%N]==0);
        }
        printf(((i==K-1)?"%d\n":"%d "),a[(p+l)%N]);
        a[(p+l)%N] = 0;
        l = (p+l)%N;
        do{
            l++;
            l %= N;
        }while(a[l]==0);
        size--;
    }
    return 0;
}
