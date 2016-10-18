#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<map>
#define FILE_IN "template.in"
#define FILE_OUT "template.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

int W,H;

pair<int,int> board[200];

int main(){
    cin >> W >> H;
    char c;
    string s;
    getline(cin,s);
    for(int i = 0; i < H; i++){
        getline(cin,s);
        for(int j = 0; j < W; j++){
            board[((int)s[j])] = make_pair(i,j);
        }
    }
    string names[3];
    getline(cin,names[0]);
    int mn = -1;
    int ans = 0;
    for(int i = 0; i < 3; i++){
        getline(cin,names[i]);
        int cost,prevX,prevY;
        cost=0;
        prevX=prevY=-1;
        while(getline(cin,s),s!=""){
            for(int j = 0; j < s.length(); j++){
                pair<int,int> p = board[((int)s[j])];
                if(prevX!=-1){
                    cost+= max(abs(p.first-prevX),abs(p.second-prevY));
                }
                prevX = p.first;prevY=p.second;
            }
        }
        if(cost<mn||mn==-1)mn=cost,ans=i;
    }
    cout << names[ans] << endl << mn << endl;
    return 0;
}
