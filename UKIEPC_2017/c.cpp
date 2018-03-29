#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d",&N);
    string col;
    int reds = 0;
    vector<int> cols;
    for(int i  = 0; i < N; i++){
        cin >> col;
        if(col == "red")
            reds++;
        else if(col == "yellow")
            cols.push_back(2);
        else if(col == "green")
            cols.push_back(3);
        else if(col == "brown")
            cols.push_back(4);
        else if(col == "blue")
            cols.push_back(5);
        else if(col == "pink")
            cols.push_back(6);
        else if(col == "black")
            cols.push_back(7);
    }
    sort(cols.begin(), cols.end(), greater<int>());
    int score = 0;
    if(cols.empty() && reds){
        printf("1\n");
        return 0;
    }
    while(reds > 0){
        score += cols[0];
        reds--;
        score++;
    }
    for(int i = 0; i < cols.size(); i++){
        score += cols[i];
    }
    printf("%d\n",score);
    return 0;
}
