#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    int a[N];
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    sort(a,a+N);
    int min = a[N-1] - a[0];
    int c = (N==2)? 0 : 1;
    for(int i = 1; i < N; i++){
        if(a[i] - a[i-1] < min){
            min = a[i] - a[i-1];
            c = 1;
        }else if(a[i]-a[i-1] == min)
            c++;
    }
    printf("%d %d\n",min,c);
}
