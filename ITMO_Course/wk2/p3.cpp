#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<queue>
#include<stack>
#define FILE_IN "queuemin.in"
#define FILE_OUT "queuemin.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

stack<long long int> inbox;
stack<long long int> outbox;
stack<long long int> minS;

long long int currentMin = 1000050000L;
long long int inboxMin = 1000050000L;

void push(long long int v){
    inbox.push(v);
    if(v<inboxMin)inboxMin=v;
}

void pop(){
    if(outbox.empty()){
        long long int tMin = 1000050000L;
        while(!inbox.empty()){
            if(inbox.top()<tMin)tMin=inbox.top();
            outbox.push(inbox.top());
            minS.push(tMin);
            inbox.pop();
        }
        inboxMin = 1000050000L;
    }
    minS.pop();
    outbox.pop();
    if(minS.size()>0) currentMin = minS.top();
    else currentMin = 1000050000L;
}

long long int getMin(){
    return min(currentMin,inboxMin);
}

int main(){
    int N;
    cin >> N;
    char c;
    long long int v;
    FILE *f = fopen(FILE_OUT,"w+");
    for(int i = 0; i<N; i++){
        cin >> c;
        if(c=='-'){
            pop();
        }else if(c=='?'){
            fprintf(f,"%lld\n",getMin());
           // cout << getMin() << endl;
        } else {
            cin >> v;
            push(v);
        }
    }
    return 0;
}
