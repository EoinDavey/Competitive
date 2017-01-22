#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<stack>
#define FILE_IN "stacks.in"
#define FILE_OUT "stacks.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;


int main(){
    int N;
    cin >> N;
    int in;
    int max = 0;
    int nStacks = 0;
    stack<int> s;
    for(int i = 0; i< N; i++){
        cin >> in;
        if(in>0||i==0)nStacks++;
        s.push(in);
    }
    int c = nStacks-1;
    int stacks[nStacks];
    memset(stacks,0,sizeof(stacks));
    while(!s.empty()){
        int p = s.top();s.pop();
        if(c<0)c=nStacks-1;
        stacks[c--]++;
        if(p>0||s.size()==1){
            //drop stack
            nStacks--;
            if(c==nStacks)c--;
        }
        for(int i = 0; i <sizeof(stacks)/sizeof(int); i++){
            cout << stacks[i] << ",";
        }
        cout << endl;
    }
    for(int i = 0; i <sizeof(stacks)/sizeof(int); i++){
        if(stacks[i]>max)max=stacks[i];
    }
    cout << max << endl;
    return 0;
}
