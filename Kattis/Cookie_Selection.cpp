#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    priority_queue<int,vector<int>,greater<int> > lft;
    priority_queue<int> rght;
    string in;
    while(cin >> in){
        if(in=="#"){
            cout << rght.top() << endl;
            rght.pop();
            if(lft.size() > rght.size()){
                rght.push(lft.top());
                lft.pop();
            }
        } else {
            int x = stoi(in);
            if(rght.empty() || x > rght.top()){
                rght.push(x);
                if(rght.size() > lft.size()+1){
                    lft.push(rght.top());
                    rght.pop();
                }
            } else {
                lft.push(x);
                if(lft.size() > rght.size()){
                    rght.push(lft.top());
                    rght.pop();
                }
            }
        }
    }
    return 0;
}
