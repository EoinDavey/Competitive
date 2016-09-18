#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int freq[300];
vector<int> up;
vector<int> lw;

void add(int l){
    if(l>=((int)'a')&&l<=((int)'z'))lw.push_back(l);
    else if(l>=((int)'A')&&l<=((int)'Z'))up.push_back(l);
}

int main(){
    string s;
    while(getline(cin,s)){
        up.resize(0);
        lw.resize(0);
        memset(freq,0,sizeof(freq));
        int mx = 0;
        for(int i = 0; i < s.length(); i++){
            int v = ((int)(s[i]));
            if((v>=((int)'a')&&v<=((int)'z'))||(v>=((int)'A')&&v<=((int)'Z'))){
                freq[v]++;
                if(freq[v]>mx){
                    mx = freq[v];
                    up.resize(0);
                    lw.resize(0);
                    add(v);
                } else if(freq[v]==mx){
                    add(v);
                }
            }
        }
        sort(up.begin(),up.end(),less<int>());
        sort(lw.begin(),lw.end(),less<int>());
        for(int i = 0; i < up.size(); i++){
            printf("%c",up[i]);
        }
        for(int i = 0; i < lw.size(); i++){
            printf("%c",lw[i]);
        }
        printf(" %d\n",mx);
    }
    return 0;
}
