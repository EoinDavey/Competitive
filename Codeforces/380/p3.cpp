#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

long long int N,K,S,T;
pair<long long int,long long int> cars[200004];
long long int stations[2000004];

bool drive(long long int c){
    long long int pos = 0L;
    long long int time = 0L;
    for(long long int i = 0; i < K; i++){
        long long int d = stations[i] - pos;
        if(d>c)return false;
        time+=max(d,3*d-c);
        pos = stations[i];
    }
    if(time>T) return false;
    return true;
}

int main(){
    cin >> N >> K >> S >> T;
    long long int c,v;
    for(long long int i = 0; i < N; i++){
        scanf(" %lld %lld",&c,&v);
        cars[i].first=v;
        cars[i].second=c;
    }
    sort(cars, cars+N);
    for(long long int i = 0; i < K; i++){
        scanf(" %lld",&stations[i]);
    }
    stations[K++] = S;
    sort(stations, stations+K);
    int res = lower_bound(cars,cars+N,true,[](pair<long long int, long long int> l, bool val) {return drive(l.first) < val;}) - cars;
    if(res == N)cout<<-1;
    else if(drive(cars[res].first)){
        int min = cars[res].second;
        for(int i = res; i < N; i++){
            if(cars[i].second < min)min=cars[i].second;
        }
        cout << min;
    }
    else cout << "-1";
    cout << endl;
    return 0;
}
