#include<bits/stdc++.h>
#include <regex>
#define INF 1000000
using namespace std;
typedef pair<int, int> ii;

struct valve {
    string name;
    int rate;
    vector<pair<string, int>> nbrs;
};

vector<valve> read() {
    string s;
    auto r = regex(R"#(Valve ([A-Z]+).*rate=([0-9]+).*valves? (.+)$)#");
    auto splt = regex(R"#([A-Z]+)#");
    smatch m;
    vector<valve> v;
    while(getline(cin, s)){
        assert(regex_search(s, m, r));
        assert(m.size() == 4);
        string name = m[1];
        string rate_s = m[2];
        int rate = stoi(rate_s);
        string vlvs_s = m[3];
        vector<pair<string, int>> vlvs;
        auto it = sregex_iterator(vlvs_s.begin(), vlvs_s.end(), splt);
        auto end = sregex_iterator();
        for(auto i = it; i != end; ++i)
            vlvs.push_back({(*i).str(), 1});
        v.push_back(valve{name, rate, vlvs});
    }
    return v;
}

vector<valve> compress(const vector<valve>& vlvs) {
    int nzcnt = 0;
    for(auto &v: vlvs)
        if(v.rate != 0)
            nzcnt++;
    assert(nzcnt <= 16);

    map<string, int> idx_mp;
    for(int i = 0; i < vlvs.size(); ++i)
        idx_mp[vlvs[i].name] = i;
    map<ii, int> dst;
    for(int i = 0; i < vlvs.size(); ++i)
        for(int j = 0; j < vlvs.size(); ++j)
            dst[{i, j}] = INF;
    for(int i = 0; i < vlvs.size(); ++i){
        dst[{i, i}] = 0;
        for(const auto& nb : vlvs[i].nbrs) {
            dst[{i, idx_mp[nb.first]}] = 1;
        }
    }
    for(int k = 0; k < vlvs.size(); ++k)
        for(int i = 0; i < vlvs.size(); ++i)
            for(int j = 0; j < vlvs.size(); ++j)
                dst[{i, j}] = min(dst[{i, j}], dst[{i, k}] + dst[{k, j}]);
    vector<valve> c;
    for(int i = 0; i < vlvs.size(); ++i){
        vector<pair<string, int>> nbs;
        if (vlvs[i].name != "AA" && vlvs[i].rate == 0)
            continue;
        for(int j = 0; j < vlvs.size(); ++j){
            if(i == j)
                continue;
            if (vlvs[j].rate == 0)
                continue;
            nbs.push_back({vlvs[j].name, dst[{i, j}]});
        }
        c.push_back(valve{vlvs[i].name, vlvs[i].rate, nbs});
    }
    return c;
}

map<pair<ii, int>, int> memo;
int f(int t, int pos, int op_set, const vector<valve> &vlvs, const map<string, int> &idx_map) {
    if(t >= 30)
        return 0;
    auto m = memo.find({{t, pos}, op_set});
    if(m != memo.end())
        return m->second;
    int mx = 0;
    for(const auto &vp : vlvs[pos].nbrs) {
        int v = idx_map.find(vp.first)->second;
        int d = vp.second;
        if((op_set & (1 << v)) != 0)
            continue;
        if(t + d + 1 > 30)
            continue;
        mx = max(mx, (30 - (t+d + 1)) * vlvs[v].rate +
                f(t + d + 1, v, op_set | (1 << v), vlvs, idx_map));
    }
    memo[{{t, pos}, op_set}] = mx;
    return mx;
}

int main(){
    auto c = compress(read());
    map<string, int> idx_map;
    for(int i = 0; i < c.size(); ++i)
        idx_map[c[i].name] = i;
    int s = 0;
    for(int i = 0; i < c.size(); ++i)
        if(c[i].name == "AA")
            s = i;
    assert(c[s].name == "AA");

    cout << f(0, s, (1 << s), c, idx_map) << endl;

    int mx = 0;
    for(int st = 0; st < (1 << c.size()); ++st) {
        int el_st = ((1<<c.size()) - 1 ) & (~st);
        assert((st | el_st) == (1 << c.size()) - 1);
        assert((st & el_st) == 0);

        int hm = f(4, s, (1 << s) | st, c, idx_map);
        int el = f(4, s, (1 << s) | el_st, c, idx_map);
        mx = max(mx, hm + el);
    }
    cout << mx << endl;
    return 0;
}
