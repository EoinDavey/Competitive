#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) cin >> x >> y >> z
#define rd2(x,y) cin >> x >> y
#define rd(x) cin >> x
#define pr3(x,y,z) cout << x << ' ' << y << ' ' << z << endl
#define pr2(x,y) cout << x << ' ' << y << endl
#define pr(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << ' ' << endl
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

struct node {
    node* child[26];
    bool end;
    node(){
        memset(child, 0, sizeof(child));
        end = false;
    }
    ~node(){
        for(int i = 0; i < 26; ++i)
            if(child[i])
                delete child[i];
    }
};

int board[4][4];
int used[4][4];
string cur;
const int mvs[][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
const int scr[] = {0,0,0,1,1,2,3,5,11};
int score;
set<string> st;
string mxStr;

void insert(string &s, int c, node * root) {
    if(c==s.size()){
        root->end=true;
        return;
    }
    if(root->child[s[c]-'A'] == 0)
        root->child[s[c]-'A'] = new node();
    insert(s, c+1, root->child[s[c]-'A']);
}

bool is_valid(int x, int y){ return x>=0 && y >= 0 && x < 4 && y < 4;}

void trav(int x, int y, node * root) {
    used[x][y] = true;
    cur.pb(board[x][y]);
    if(root->end){
        if(!st.count(cur)){
            st.insert(cur);
            score += scr[cur.size()];
            if(cur.size() > mxStr.size())
                mxStr = cur;
            else if(cur.size()==mxStr.size() && cur < mxStr)
                mxStr = cur;
        }
    }
    for(int k = 0; k < 8; ++k){
        int nx,ny;
        nx = x + mvs[k][0];
        ny = y + mvs[k][1];
        if(!is_valid(nx,ny))
            continue;
        if(!used[nx][ny] && root->child[board[nx][ny]-'A'])
            trav(nx,ny,root->child[board[nx][ny]-'A']);
    }
    cur.pop_back();
    used[x][y] = false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N; rd(N);
    string s;
    node * root = new node();
    for(int i = 0; i < N; ++i){
        rd(s);
        insert(s, 0, root);
    }
    int q;
    rd(q);
    for(int i = 0; i < q; ++i){
        for(int j = 0; j < 4; ++j){
            rd(s);
            for(int k = 0; k < 4; ++k)
                board[j][k] = s[k];
        }

        score=0;
        cur.clear();
        st.clear();
        mxStr = "";
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
                if(root->child[board[j][k]-'A'])
                    trav(j, k, root->child[board[j][k]-'A']);
            }
        }
        pr(score << ' ' << mxStr << ' ' << st.size());
    }
    
    delete root;
    return 0;
}
