#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
const int MX_N = 400;
int N;
int a[MX_N];
bool used[MX_N];
long long totSum=0;
long long out = 0;

void choose(int count, int k){
    if(count<3){
        for(int i =k; i < N; i++){
            if(!used[i]){
                used[i]=true;
                choose(count+1,i+1);
                used[i]=false;
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i < N; i++)
        if(used[i])
            sum+=a[i];
    if(sum<200)
        out+=sum;
}

int main(){
    scanf("%d",&N);
    for(int i =0; i < N; i++)
        scanf("%d",&a[i]),totSum+=a[i];
    totSum*= ((long long) (1L<<(N-1L)));
    choose(0,0);
    printf("%lld\n",totSum-out);
    return 0;
}
