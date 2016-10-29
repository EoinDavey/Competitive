#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#define FILE_IN "testgen.in"
#define FILE_OUT "testgen.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;
bool sieve[3202];
vector<int> primes;

int main(){
    int N;
    cin >> N;
    for(int i = 2; i < 3200; i ++){
        if(!sieve[i]){
            for(int j = i; j<3200; j+=i){
                sieve[j]=true;
            }
            primes.push_back(i);
        }
    }
    long long int t = 2;
    long long int c = t;
    long long int min = 0;
    vector<int> powers;
    vector<pair<long long int, long long int> > pairs;
    while(true){
        powers.clear();
        c = t;
        int twos=0;
        bool gFour = false;
        for(int p = 0; p<primes.size()&&c>1; p++){
            while(c%primes[p]==0){
                c/=primes[p];
                if(p>0)powers.push_back(primes[p]);
                else twos++;
                if(primes[p]>4)gFour = true;
            }
        }
        if(gFour){
            for(int i = 0; i < twos; i++){
                powers.push_back(2);
            }
        }else{
            for(int i = 0; i < twos/3; i++){
                powers.push_back(4);powers.push_back(2);
            }
            for(int i = 0; i < twos%3; i++){
                powers.push_back(2);
            }
        }
        long long int o = 1;
        sort(powers.begin(),powers.end(),greater<int>());
        long long int prev = 0;
        long long int cur = 0;
        bool flow = false;
        for(int p = 0; p < powers.size()&&!flow; p++){
            cur =pow(primes[p],(powers[p]-1));
            if(o*cur<o)flow=true;
            o*=cur;
        }
        if(!flow)pairs.push_back(make_pair(o,t));
        if(t==240){
            break;
        }
        if(o<=N&&!flow)min = o;
        t++;
    }
    sort(pairs.begin(),pairs.end(),less<pair<long long int, long long int> >());
    pair<long long int,long long int> p;
    int prev = 0;
    for(int i = 0; i < pairs.size(); i++){
        p = pairs[i];
        if(p.second>prev)cout << p.first << endl, prev = p.second;
    }
    cout << (N-min+1) << endl;
    return 0;
}
