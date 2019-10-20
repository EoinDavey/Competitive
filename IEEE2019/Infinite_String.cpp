#include <bits/stdc++.h>

using namespace std;

long long power(long long n, long long p) {
	if(p == 0)
		return 1;
	if(p % 2 == 0) {
		long long x = power(n, p / 2);
		return x * x;
	}
	return n * power(n, p - 1);
}

int main() {
	long long T;
	cin >> T;
	while(T --> 0) {
		long long num_chars, requested_index;
		cin >> num_chars >> requested_index;
		if(num_chars == 1) {
			cout << (char)('a') << endl;
			continue;
		}

		requested_index++;
		long long sum = 0;
		long long l;
		for(l = 1; ; l++) {
			long long pwr = l * power(num_chars, l);

			if(LLONG_MAX - pwr < sum) {
				break;
			}
			sum += pwr;
			
			if(sum > requested_index) {
				sum -= pwr;
				break;
			}
			if(sum == requested_index) {
				break;
			}
		}
		long long letter_index = requested_index - sum;

		if(letter_index == 0) {
			cout << (char)('a' + num_chars - 1) << endl;
			continue;
		}

		//cout << letter_index << endl;

		long long indent;
		for(indent = l; ; indent--, letter_index--) {
			long long divides = (long long)floor((double)(letter_index - 1) / (power(num_chars, indent - 1) * l));

			letter_index -= (power(num_chars, indent - 1) * l) * divides;

		//	cout << letter_index << " " << divides << endl;

			if((letter_index - 1) % l == 0) {
				cout << (char)('a' + divides) << endl;
				break;
			}
		}
	}
}
