#include<bits/stdc++.h>
using namespace std;

const int MX_N = 1000010;
int orig[2][MX_N],N;

bool check(int m){
    vector<int> nRow[2];
    for(int i = 0; i < N; i++)
        if(orig[0][i] > m)
            nRow[0].push_back(orig[0][i]);
    for(int i = 0; i < N; i++)
        if(orig[1][i] > m)
            nRow[1].push_back(orig[1][i]);
    if(nRow[0].size()%2 | nRow[1].size()%2)
        return false;
    for(int i = 0; i < nRow[0].size(); i+=2){
        if(nRow[0][i]!=nRow[0][i+1])
            return false;
    }
    for(int i = 0; i < nRow[1].size(); i+=2){
        if(nRow[1][i]!=nRow[1][i+1])
            return false;
    }
    return true;
}

bool comp(int c, bool b) {
    return check(c) < b;
}

int main(){
    scanf("%d",&N);
    unordered_set<int> uniq;
    for(int i = 0; i < N; i++){
        scanf("%d",&orig[0][i]);
        uniq.insert(orig[0][i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d",&orig[1][i]);
        uniq.insert(orig[1][i]);
    }
    uniq.insert(0);
    vector<int> vals;
    copy(uniq.begin(), uniq.end(), back_inserter(vals));
    sort(vals.begin(), vals.end());
    vector<int>::iterator v = lower_bound(vals.begin(), vals.end(), true, comp);
    printf("%d\n",*v);
    return 0;
}
