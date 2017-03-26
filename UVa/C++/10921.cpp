#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <queue>
#include <stdint.h>

using namespace std;

int out[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main(){
    string in;
    while(cin >> in){
        for(int i =0; i < in.length(); i++){
            char c = in[i];
            if(c>='A' && c <= 'Z')
                printf("%d",out[c-'A']);
            else
                printf("%c",c);
        }
        printf("\n");
    }
	return 0;
}
