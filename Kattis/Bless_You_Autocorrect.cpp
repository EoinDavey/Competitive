#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define ii pair<int, int>
#define fi first
#define se second
#define mk make_pair
#define mt make_tuple

const int MX_N = 200002;
vector<map<char, int> > trie;
vector<vector<int> > tAdj;
int N, M;
vector<int> queryMap;

int insert(const string& s, int root, int ind, bool addAuto) {
	if(s.size()==ind){
		if(!addAuto)
			queryMap.pb(root);
		if(addAuto && trie[root].find('A') == trie[root].end())
			trie[root]['A'] = -1;
		return root;
	}
	if(trie[root].find(s[ind]) == trie[root].end()){
		trie[root][s[ind]] = trie.size();
		trie.pb(map<char,int>{});
		tAdj.pb(vector<int>{});
	}
	int nxt = trie[root][s[ind]];
	tAdj[nxt].pb(root); // add delete from next
	trie[root][s[ind]] = nxt;
	tAdj[root].pb(nxt); // add edge from root to nxt
	int end = insert(s, trie[root][s[ind]], ind+1, addAuto);

	//check if already have auto-jump
	if(addAuto && root && trie[root].find('A') == trie[root].end()){
		trie[root]['A'] = end;
		tAdj[root].pb(end); // add edge from root to end 
	}
	return end;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> N >> M;
	string s;
	trie.pb(map<char, int>{});
	tAdj.pb(vector<int>{});
	for(int i = 0; i < N; ++i){
		cin >> s;
		insert(s, 0, 0, true);
	}
	vector<string> qs(M);
	for(int i = 0; i < M; ++i){
		cin >> qs[i];
		insert(qs[i], 0, 0, false);
	}
	queue<int> q;
	int dist[tAdj.size()]; memset(dist, 0, sizeof(dist));
	q.push(0);
	dist[0] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : tAdj[u]){
			if(!dist[v]){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	for(int i = 0; i < M; ++i){
		printf("%d\n", dist[queryMap[i]]-1);
	}
	return 0;
}
