#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll a[8];
set<ll> sets[100];

int main(){
	scanf("%lld",&N);
	for(ll i = 0; i < N; ++i)
		scanf("%lld",&a[i]);
	sets[0].insert(0LL);
	for(ll i = 0; i < N; ++i){
		sets[1<<i].insert(a[i]);
	}
	bool survive = true;
	while(survive){
		survive = false;
		for(ll i = 0; i < (1<<N); ++i){
			for(ll j = 0; j < (1<<N); ++j){
				if((i&j) > 0)//non-disjoint
					continue;
				ll ns = i | j;
				for(ll a : sets[i]){
					for(ll b : sets[j]){
						if(sets[ns].count(a+b) <= 0){
							sets[ns].insert(a+b);
							survive = true;
						}
						if(sets[ns].count(a-b) <= 0){
							sets[ns].insert(a-b);
							survive = true;
						}
						if(sets[ns].count(a*b) <= 0){
							sets[ns].insert(a*b);
							survive = true;
						}
						if(b!=0 && a%b==0 && sets[ns].count(a/b) <= 0){
							sets[ns].insert(a/b);
							survive = true;
						}
					}
				}
			}
		}
	}
	set<ll> all;
	for(ll i = 0; i < (1<<N); ++i)
		for(ll a : sets[i])
			all.insert(a);
	ll ans = 0;
	for(ll i = 1;;++i){
		if(all.count((ll)i) <= 0){
			ans = i;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
