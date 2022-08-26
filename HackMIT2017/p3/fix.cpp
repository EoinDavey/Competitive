#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main(){
    unordered_set<string> set;
    string str;
    while(getline(cin,str)){
        if(set.count(str)==0){
            set.insert(str);
            cout << str << endl;
        }
    }
    return 0;
}
