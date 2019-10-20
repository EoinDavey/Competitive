#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(b, b + m);
	int counter_a = 0;
	int counter_b = 0;
	while(counter_a < n) {
		if(counter_b < m && a[counter_a] > b[counter_b]) {
			cout << b[counter_b] << " ";
			counter_b++;
		} else {
			cout << a[counter_a] << " ";
			counter_a++;
		}
	}
	while(counter_b < m)
		cout << b[counter_b++] << " ";
	cout << endl;
}
