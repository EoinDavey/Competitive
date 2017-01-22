#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int main(){
    int two,three,five,six;
    scanf("%d %d %d %d",&two,&three,&five,&six);
    int sum = 0;
    while(two > 0 && five > 0 && six > 0){
        sum+=256;
        two--;five--;six--;
    }
    while(two > 0 && three > 0){
        sum+=32;
        two--;
        three--;
    }
    cout << sum << endl;
    return 0;
}
