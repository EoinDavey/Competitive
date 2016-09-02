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
int main(){
	char f[] = {'A','B','C','D','E','F','G','H','I','J','K','L',
				'M','N','O','P','Q','R','S','T','U','V','W','X',
				'Y','Z','1','2','3','4','5','6','7','8','9'};
	char r[] = {'A',' ',' ',' ','3',' ',' ','H','I','L',' ','J',
				'M',' ','O',' ',' ',' ','2','T','U','V','W','X',
				'Y','5','1','S','E',' ','Z',' ',' ','8',' '};
	string s;
	while(getline(cin,s)){
		//check for palindrome
		bool palindrome = true;
		for(int i = 0; i <= s.length()/2 && palindrome; i++){
			if(s[i]!=s[s.length()-i-1]){
				palindrome = false;
			}
		}
		//check for mirror
		bool mirror = true;
		for(int i = 0; i<=s.length()/2 && mirror; i++){
			char c = s[i];
			char g = ' ';
			for(int j = 0; j < sizeof(f)/sizeof(char); j++){
				if(f[j]==c){
					g = r[j];
				}
			}
			//cout << c << "->" << g << endl;
			if(g==' ' ||s[s.length()-i-1]!=g){
				mirror = false;
			}
		}
		cout << s;
		if(palindrome&&mirror){
			cout << " -- is a mirrored palindrome.\n";
		} else if(palindrome){
			cout << " -- is a regular palindrome.\n";
		} else if(mirror){
			cout << " -- is a mirrored string.\n";
		} else cout << " -- is not a palindrome.\n";
		cout << endl;
	}
	return 0;
}