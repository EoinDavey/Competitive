#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int N;

int main(){
    cin >> N;
    int a[N], b[N];
    for(int i = 0; i < N; i++){
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]!=b[i]){
            printf("rated\n");
            return 0;
        }
    }
    for(int i = 1; i < N; i++){
        if(a[i] > a[i-1]){
            printf("unrated\n");
            return 0;
        }
    }
    printf("maybe\n");
    return 0;
}
