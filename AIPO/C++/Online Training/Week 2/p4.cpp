#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
long long a[100000];
int main() {
	int n;
	cin >> n;
	for (int i = 0, x; i<n; i++) {
		cin >> x;
		a[x] += x;
	}
	for (int i = 2; i <= 100000; i++)a[i] = max(a[i] + a[i - 2], a[i - 1]);
	cout << a[100000];
}