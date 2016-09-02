#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

int N;
string S;
int len[100001];
vector<char> letters;
bool set[200];

int main(){
    cin >> N;
    cin >> S;
    memset(len,-1,sizeof(len));
    for(int i = 0; i < S.length();i++){
        if(!set[(int)S[i] - 'A']){
            set[(int)S[i]-'A']=true;
            letters.push_back(S[i]);
        }
    }
    int lim = pow(10,9);
    for(int i = 0; i < letters.size();i++){
        int last = -1;
        for(int j = 0; j < N; j++){
            if(letters[i]==S[j]){
                last = j;
            }
            if(last==-1)len[j]=lim;
            else len[j] = max(len[j], j-last+1);
        }
    }

    int mn = -1;
    for(int i = 0; i < N;i++){
        if((len[i] < mn || mn==-1)&&len[i]!=-1)mn=len[i];
    }
    cout << mn << endl;
    return 0;
}

