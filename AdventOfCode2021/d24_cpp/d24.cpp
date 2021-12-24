#include<bits/stdc++.h>
#define ll long long int
using namespace std;

string findSoln(vector<int> &forms, vector<int> &dxs, vector<int> &dys, ll z, int idx, bool max) {
    if(idx >= forms.size())
        return z == 0LL ? "" : "fail";

    int frm = forms[idx];
    int dx = dxs[idx];
    int dy = dys[idx];

    if(frm == 1) {
        int strt = max ? 9 : 1;
        int end = max ? 0 : 10;
        for(int i = strt; i != end; max ? i-- : i++) {
            ll nz = 26LL * z + ((ll) i + dy);
            string sub = findSoln(forms, dxs, dys, nz, idx + 1, max);
            if(sub != "fail")
                return to_string(i) + sub;
        }
        return "fail";
    }

    ll t = dx + (z % 26LL);
    if(t < 1 || t > 9)
        return "fail";
    ll nz = z / 26;
    string sub = findSoln(forms, dxs, dys, nz, idx + 1, max);
    if(sub != "fail")
        return to_string(t) + sub;
    return "fail";
}

void getBlocks() {
    string s;
    vector<int> forms;
    vector<int> dxs;
    vector<int> dys;
    int form = -1;
    int dx = -1;
    int dy = -1;
    while(getline(cin, s)) {
        auto ss = stringstream(s);
        string com, l, r;
        char reg;
        ss >> com;
        if(com == "inp") {
            ss >> reg;
            if(dx != -1) {
                forms.push_back(form);
                dxs.push_back(dx);
                dys.push_back(dy);
            }
            form = 1;
            dx = -1;
            dy = -1;
        } else {
            ss >> l >> r;
            if(com == "div" && l == "z" && r == "26")
                form = 2;
            if(com == "add" && l == "x" && r != "z")
                dx = stoi(r);
            if(com == "add" && l == "y" && r != "w")
                dy = stoi(r);
        }
    }
    forms.push_back(form);
    dxs.push_back(dx);
    dys.push_back(dy);
    cout << "Part 1: " << findSoln(forms, dxs, dys, 0, 0, true) << endl;
    cout << "Part 2: " << findSoln(forms, dxs, dys, 0, 0, false) << endl;
}

int main() {
    getBlocks();
    return 0;
}
