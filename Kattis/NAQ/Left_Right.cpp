#include<bits/stdc++.h>
using namespace std;
const int MX_N = 200002;
int l_run[MX_N];
int N;
string S;

int main(){
    cin >> N;
    cin >> S;
    int run = S[N-1] == 'L';
    l_run[N-1] = run;
    for(int i = N-2; i >=0; --i)
        if(S[i]=='L'){
            ++run;
            l_run[i] = run;
        }else{
            l_run[i]=run;
            run = 0;
        }
    int ind = S[0]=='R' ? 0 : l_run[0];
    cout << ind+1 << endl;
    int i = 0;
    while(i < N-1){
        if(S[i]=='R'){
            ind+=l_run[i]+1;
            cout << ind+1 << endl;
            ++i;
            continue;
        }
        for(int k = 1; i < N-1 && S[i]=='L'; ++k, ++i)
            cout << ind-k+1 << endl;
    }
    return 0;
}
