#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int mx_n = 100001;
int N;
int a[mx_n];

int main(){
    int N; scanf("%d",&N);
    vector<int> even;
    vector<int> odd;
    for(int i = 0; i < N; i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }
    int sum = 0;
    for(int i = 0; i < even.size(); i++)
        if(even[i] > 0)
            sum+=even[i];
    sort(odd.begin(), odd.end(),greater<int>());
    sum+=odd[0];
    for(int i = 1; i < odd.size(); i+=2){
        if(i+1 >= odd.size())
            break;
        if(odd[i]+odd[i+1] > 0)
            sum+=odd[i] + odd[i+1];
    }
    printf("%d\n",sum);
    return 0;
}
