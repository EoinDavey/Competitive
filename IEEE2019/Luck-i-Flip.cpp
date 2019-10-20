#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int num_bets;
vector<int> bets;
int n;
int wins[101];
bool taken[1 << 22];

int get_winner(int result) {
    int best_result = -1;
    int best_person = -1;
    for(int i = 0; i < num_bets; i++) {
        int correct_result = (((~bets[i]) ^ result) & ((1 << n) - 1));
        int sum = __builtin_popcount(correct_result);

        if(sum > best_result) {
            best_result = sum;
            best_person = i;
        } else if(sum == best_result) {
            best_person = -1;
        }
    }
    return best_person;
}

int main() {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(wins, 0, sizeof wins);
    cin >> num_bets;
    for(int i = 0; i < num_bets; i++) {
        string s;
        cin >> s;
        n = s.size();
        int bitmask = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '1')
                bitmask |= (1 << j);
        }
        if(!taken[bitmask]) {
           taken[bitmask] = true;
           bets.push_back(bitmask);
        }
    }
    for(int i = 0; i < (1 << n); i++) {
        int winner = get_winner(i);
        if(winner != -1)
            wins[winner]++;
    }
    int worst = 1 << n;
    for(int i = 0; i < num_bets; i++)
        worst = min(worst, wins[i]);
    cout << worst << endl;
}
