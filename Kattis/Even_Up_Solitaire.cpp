#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; scanf("%d",&N);
    stack<bool> st;
    int in;
    while(N-->0){
        scanf("%d",&in);
        st.push(in%2==0);
        while(st.size() > 1){
            bool b1 = st.top(); st.pop();
            bool b2 = st.top(); st.pop();
            if(b1==b2)
                continue;
            st.push(b2);
            st.push(b1);
            break;
        }
    }
    printf("%d\n",st.size());
    return 0;
}
