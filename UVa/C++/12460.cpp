#include<iostream>
#include<map>
#include<cstdio>
#include<string>

using namespace std;

map<string,string> p;
map<string,int> r;

string find_parent(string i){
    if(p[i]==i)
        return i;
    return p[i] = find_parent(p[i]);
}

void join(string i, string j){
    string pi = find_parent(i);
    string pj = find_parent(j);
    if(pi==pj)
        return;
    p[pi]=pj;
}

void proc(string in){
    string _in = in;
    p[in]=in;
    for(int i = 0; i < in.length(); i++){
        char c = in[i];
        for(char a='a'; a<='z'; a++){
            in[i]=a;
            if(p[in]!="")
                join(_in,in);
        }
        in[i]=c;
    }
}

int main(){
    string in;
    while(1){
        cin >> in;
        if(in=="--")
            break;
        proc(in);
    }
    string a,b;
    while(cin >> a >> b){
        if(find_parent(a)==find_parent(b)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
