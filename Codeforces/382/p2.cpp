#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N, n1, n2;

int main(){
    cin >> N >> n1 >> n2;
    int t = max(n1,n2);
    int l = min(n1,n2);
    int in[N];
    for(int i = 0; i < N; i++) scanf(" %d",&in[i]);
    sort(in, in + N, greater<int>());
    double s1,s2;s1=s2=0.0;
    int i = 0;
    for(; i < l; i++)s1+=in[i];
    for(int j = 0; j < t; j++)s2+=in[i+j];
    printf("%.8f\n",(s1/l) + (s2/t));
    return 0;
}
