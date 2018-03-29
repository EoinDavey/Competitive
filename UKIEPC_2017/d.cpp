#include <bits/stdc++.h>
using namespace std;
char a[10000];

vector<pair<int,int> > swps;

void swap(int i, int j){
    if(i==j)
        return;
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
    swps.push_back({i+1,j+1});
}

void qSort(int L, int R){
    if(L >= R-1)
        return;
    char pivot = a[L];
    int sI = L+1;
    for(int i = L+1; i <= R; ++i){
        if(a[i] < pivot)
            swap(i,sI++);
    }
    swap(L,sI-1);
    qSort(L,sI-1);
    qSort(sI,R);
}

int main() {
    scanf("%s",a);
    int N = strlen(a);
    qSort(0,N-1);
    for(auto i = swps.rbegin(); i != swps.rend(); i++)
        printf("%d %d\n",max(i->first,i->second),min(i->first,i->second));
    return 0;
}
