#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int MX_N = 2 * 100 * 1000 + 5;

map<int, int> cnt;
int N;
int rsum[MX_N];
int ccnt[MX_N];

int main(){
    scanf("%d",&N);
    int a;
    int mxa = 0;
    for(int i = 0; i < N; ++i){
        scanf("%d",&a);
        cnt[a]++;
        mxa = max(mxa, cnt[a]);
    }
    for(const auto& i : cnt)
        ccnt[i.se]+=1;
    for(int i = MX_N -2; i >= 0; --i)
        rsum[i] = rsum[i+1] + ccnt[i];

    int mx = 0;
    for(int i = 1; i <=mxa; ++i){
        //ends at i
        int sm = 0;
        int cnt = 0;
        int j = i;
        while(j && rsum[j] > cnt){
            sm+=j;
            cnt+=1;
            j = j%2==0 ? j / 2 : 0;
        }
        mx = max(mx, sm);
    }
    printf("%d\n", mx);
    return 0;
}
