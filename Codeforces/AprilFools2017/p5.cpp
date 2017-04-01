#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    bool a,b,c,d;
    scanf(" %d %d %d %d",&a,&b,&c,&d);
    bool or1 = a^b;
    bool nor1 = (c||d);
    bool and1 = b&&c;
    bool or2 = a^d;
    bool and2 = or1&&nor1;
    bool nor2 = (and1||or2);
    cout << (and2^nor2) << endl;
    return 0;
}
