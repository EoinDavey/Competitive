#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,a,b;
    while(scanf("%d",&N)==1){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool sfail,qfail,pqfail;
        sfail=qfail=pqfail=false;
        for(int i = 0; i < N; i++){
            scanf("%d %d",&a,&b);
            if(a==1){
                s.push(b);
                q.push(b);
                pq.push(b);
            } else {
                int x;
                if(!s.empty()){
                    x = s.top(); s.pop();
                    if(x!=b)
                        sfail=true;
                } else {
                    sfail = true;
                }
                if(!q.empty()){
                    x = q.front(); q.pop();
                    if(x!=b)
                        qfail=true;
                } else 
                    qfail=true;
                if(!pq.empty()){
                    x = pq.top(); pq.pop();
                    if(x!=b)
                        pqfail=true;
                } else
                    pqfail=true;
            }
        }
        if(sfail&&qfail&&pqfail)
            puts("impossible");
        else if(((int)sfail) + ((int) qfail) + ((int) pqfail) < 2)
            puts("not sure");
        else if(!sfail)
            puts("stack");
        else if(!qfail)
            puts("queue");
        else if(!pqfail)
            puts("priority queue");
    }
    return 0;
}
