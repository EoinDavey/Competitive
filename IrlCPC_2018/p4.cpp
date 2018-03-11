#include <bits/stdc++.h>

using namespace std;
const long long int INF = 1000*1000*1000;

int main() {
	int N;
	scanf("%d",&N);
	long long sum = 0; 
	long long x;
	long long record = -INF;
	for(int i = 0; i < N; i++){
		scanf("%lld",&x);
		sum += x;
		if(sum < 0) sum = 0L;
		record = max(sum,record);
	}
	printf("%lld\n",record);
	return 0;
}
