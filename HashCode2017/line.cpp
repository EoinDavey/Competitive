#include<string>
#include<iostream>
#include<sstream>

using namespace std;

int main(){
    int N; cin >> N;
    N++;
    string s;
    int in;
    for(int i = 0; i < N; i++){
        getline(cin, s);
        stringstream ss(s);
        while(ss >> in){
            printf("%d",in);
        }
        printf("end of line\n");
    }
    return 0;
}
