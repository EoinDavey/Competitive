#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int l;
	queue<int> f;
	cin >> l;
	while (l) {
		if (f.size()) {
			f.push(f.front());
			f.pop();
		}
		f.push(l - 1);
		l--;
	}
	vector<int> v;
	while(!f.empty()){
		int q = f.front();f.pop();
		v.push_back(q);
	}
	for(int i = v.size()-1; i >= 0; --i){
		cout << v[i] << " ";
	}
	cout << "\n";
	return 0;
}
