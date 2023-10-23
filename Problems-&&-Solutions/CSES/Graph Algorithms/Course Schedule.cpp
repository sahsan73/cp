/*
Problem Statement: https://cses.fi/problemset/task/1679/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m, d[mxN];
vector<int> adj[mxN];

void solve() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		++d[b];
	}
	queue<int> qu;
	for(int i=0; i<n; ++i)
		if(d[i]==0)
			qu.push(i);
	vector<int> ans;
	while(qu.size()) {
		int u=qu.front();
		qu.pop();
		ans.push_back(u);
		for(int v: adj[u]) {
			--d[v];
			if(d[v]==0)
				qu.push(v);
		}
	}
	if(ans.size()<n)
		cout << "IMPOSSIBLE";
	else {
		for(int i=0; i<n; ++i)
			cout << ans[i]+1 << " ";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
