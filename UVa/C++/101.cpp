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
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<vector<int>> stacks(n);
	int loc[n];
	int count = 0;
	int inc = 0;
	for(vector<vector<int>>::iterator i = stacks.begin(); i!=stacks.end(); i++){
		i->push_back(count++);
		loc[inc] = inc;
		inc++;
	}
	string s;
	while(true){
		string com,mov;
		int a,b;
		cin >> com;
		if(com=="quit")break;
		cin >> a >> mov >> b;
		int aLoc,bLoc;
		aLoc = loc[a];
		bLoc = loc[b];
		if(aLoc==bLoc) continue;
		if(com=="move" && mov == "onto"){
			int aLoc,bLoc;
			aLoc = loc[a];
			bLoc = loc[b];
			for(vector<int>::reverse_iterator i = stacks[aLoc].rbegin(); i!= stacks[aLoc].rend(); i++){
				int c = *i;
				if(c==a) break;
				loc[c] = c;
				stacks[c].push_back(c);
				stacks[aLoc].pop_back();
			}
			for(vector<int>::reverse_iterator i = stacks[bLoc].rbegin(); i!= stacks[bLoc].rend(); i++){
				int c = *i;
				if(c==b) break;
				loc[c] = c;
				stacks[c].push_back(c);
				stacks[bLoc].pop_back();
			}
			loc[a]=bLoc;
			stacks[bLoc].push_back(a);
			stacks[aLoc].pop_back();
		}
		if(com=="move" && mov == "over"){
			int aLoc,bLoc;
			aLoc = loc[a];
			bLoc = loc[b];
			for(vector<int>::reverse_iterator i = stacks[aLoc].rbegin(); i!= stacks[aLoc].rend(); i++){
				int c = *i;
				if(c==a) break;
				loc[c] = c;
				stacks[c].push_back(c);
				stacks[aLoc].pop_back();
			}
			loc[a]=bLoc;
			stacks[bLoc].push_back(a);
			stacks[aLoc].pop_back();
		}
		if(com=="pile"&&mov=="onto"){
			int aLoc,bLoc;
			aLoc = loc[a];
			bLoc = loc[b];
			for(vector<int>::reverse_iterator i = stacks[bLoc].rbegin(); i!= stacks[bLoc].rend(); i++){
				int c = *i;
				if(c==b) break;
				loc[c] = c;
				stacks[c].push_back(c);
				stacks[bLoc].pop_back();
			}
			vector<int> temp;
			bool stop = false;
			for(vector<int>::reverse_iterator i = stacks[aLoc].rbegin(); i!=stacks[aLoc].rend() && !stop;i++){
				if(*i==a) stop = true;
				loc[*i]=bLoc;
				temp.push_back(*i);
				stacks[aLoc].pop_back();
			}
			for(vector<int>::reverse_iterator i = temp.rbegin(); i!=temp.rend(); i++){
				stacks[bLoc].push_back(*i);
			}
		}
		if(com=="pile"&&mov=="over"){
			int aLoc,bLoc;
			aLoc=loc[a];
			bLoc=loc[b];
			vector<int> temp;
			bool stop = false;
			for(vector<int>::reverse_iterator i = stacks[aLoc].rbegin(); i!=stacks[aLoc].rend() && !stop;i++){
				if(*i==a) stop = true;
				loc[*i]=bLoc;
				temp.push_back(*i);
				stacks[aLoc].pop_back();
			}
			for(vector<int>::reverse_iterator i = temp.rbegin(); i!=temp.rend(); i++){
				stacks[bLoc].push_back(*i);
			}
		}
	}
	inc = 0;
	for(vector<vector<int>>::iterator i = stacks.begin(); i!=stacks.end();i++){
		cout << inc++ << ":";
		for(vector<int>::iterator j = i->begin(); j!= i->end(); j++){
			cout <<" "<< *j;
		}
		cout << endl;
	}
	return 0;
}