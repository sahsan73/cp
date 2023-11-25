/*
Problem Statement: https://cses.fi/problemset/task/1132
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: RE-ROOTING + DYNAMIC PROGRAMMING
*/
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=2e5;
// d[i] --> height of the subtree (i)
int n, d[mxN], ans[mxN];
vector<int> adj[mxN];

// calculate depth of each node in a tree
// rooted at (0)
void dfs(int u=0, int p=-1) {
	//d[u]=1;
	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
		d[u]=max(d[u], d[v]+1);
	}
}

void dfs2(int u=0, int p=-1, int pd=0) {
	//cout << "(" << u << ", " << p << ", " << pd << ")\n";
	ans[u]=max(pd, d[u]);
	vector<ar<int, 2>> w;
	w.push_back({pd, -1});
	for(int v: adj[u]) {
		if(v^p)
			w.push_back({d[v]+1, v});
	}
	sort(w.begin(), w.end(), greater<ar<int, 2>>());
	
	for(int v: adj[u]) {
		if(v^p)
			dfs2(v, u, w[0][1]==v?w[1][0]+1:w[0][0]+1);
	}
}

int main() {
	cin >> n;
	for(int i=1, a, b; i<n; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	dfs2();
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";

	return 0;
}
