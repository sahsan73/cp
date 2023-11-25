/*
Diameter == Longest path in the tree

We have two cases for a longest path:
    - Case I: Longest path contain root node
    - Case II: Longes path does NOT contain root node
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
// d[i] --> height of a subtree (i)
int n, d[mxN], ans;
vector<int> adj[mxN];

void dfs(int u, int p) {
	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
		ans=max(ans, d[u]+d[v]+1);
		d[u]=max(d[u], d[v]+1);
	}
}

int main() {
	cin >> n;
	for(int i=0, a, b; i<n-1; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	cout << ans;

	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BRUTE FORCE
    - For each root node, calculate distances/depths of every other nodes
    - Keep track of maximum distance found so far

Time Complexity: O(n^2)
*/
