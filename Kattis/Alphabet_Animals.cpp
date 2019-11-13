#include <bits/stdc++.h>

using namespace std;

char count_start[26];
string words[100001];

int main() {
	string last_word;
	cin >> last_word;
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> words[i];
		count_start[words[i][0] - 'a']++;
	}
	for(int i = 0; i < n; i++) {
		if(words[i][0] == last_word[last_word.size() - 1]) {
			int count_next = count_start[words[i][words[i].size() - 1] - 'a'];
			if(words[i][0] == words[i][words[i].size() - 1])
				count_next--;
			if(count_next == 0) {
				cout << words[i] << "!" << endl;
				return 0;			
			}	
		}
	}
	for(int i = 0; i < n; i++) {
		if(words[i][0] == last_word[last_word.size() - 1]) {
			cout << words[i] << endl;
			return 0;
		}
	}
	cout << "?" << endl;
}
