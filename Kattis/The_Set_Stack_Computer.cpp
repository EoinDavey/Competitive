#include<bits/stdc++.h>
using namespace std;
typedef set<int> ss;

map<ss,int> idMap;
stack<ss> st;

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        idMap.clear();
        while(!st.empty())
            st.pop();
        int N; scanf("%d",&N);
        char buff[10];
        for(int i = 0; i < N; i++){
            scanf("%s",buff);
            if(buff[0]=='P'){
                st.push(ss());
            }
            if(buff[0]=='D'){
                ss s = st.top();
                st.push(s);
            }
            if(buff[0]=='U'){
                ss s1 = st.top(); st.pop();
                ss s2 = st.top(); st.pop();
                s1.insert(s2.cbegin(),s2.cend());
                st.push(s1);
            }
            if(buff[0]=='I'){
                ss s1 = st.top(); st.pop();
                ss s2 = st.top(); st.pop();
                ss s3;
                for(auto j = s1.cbegin(); j != s1.cend(); j++)
                    if(s2.find(*j)!=s2.end())
                        s3.insert(*j);
                st.push(s3);
            }
            if(buff[0]=='A'){
                ss s1 = st.top(); st.pop();
                int id;
                auto j = idMap.find(s1);
                if(j != idMap.end()){
                    id = j->second;
                } else {
                    id = idMap.size();
                    idMap[s1]=id;
                }
                st.top().insert(id);
            }
            printf("%d\n",st.top().size());
        }
        puts("***");
    }
    return 0;
}
