#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T-->0){
        string p; cin >> p;
        int N; cin >> N;
        vector<int> vi;
        vi.reserve(N);
        int x; char _c;
        cin >> _c;
        for(int i = 0; i < N; ++i){
            cin >> x;
            vi.push_back(x);
            if(i!=N-1)
                cin >> _c;
        }
        cin >> _c;
        int L = 0;
        int R = N-1;
        int k = 0;
        for(char c : p){
            if(c=='R')
                k = 1-k;
            else {
                if(k)
                    R--;
                else
                    L++;
            }
        }
        if(L > R+1)
            cout << "error\n";
        else{
            cout << "[";
            if(k){
                for(int i = R; i >= L; --i)
                    cout << vi[i] << (i==L ? "" : ",");
            } else {
                for(int i = L; i <= R; ++i)
                    cout << vi[i] << (i==R ? "" : ",");
            }
            cout << "]\n";
        }
    }
    return 0;
}
