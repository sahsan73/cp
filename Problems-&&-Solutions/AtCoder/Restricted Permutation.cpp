/*
Problem Statement: https://atcoder.jp/contests/abc223/tasks/abc223_d
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: TOPO SORT
    - BFS, Kahn's Algorithm
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, m, indeg[mxN];
vector<int> adj[mxN];

int main() {
	cin >> n >> m;
	for(int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		++indeg[b];
	}

	set<int> st;
	for(int i=0; i<n; ++i) {
		if(indeg[i]==0)
			st.insert(i);
	}
	vector<int> order;
	while(!st.empty()) {
		int u=*st.begin();
		st.erase(u);
		for(int v: adj[u]) {
			--indeg[v];
			if(indeg[v]==0)
				st.insert(v);
		}
		order.push_back(u);
	}
	if(order.size()<n) {
		cout << -1;
		return 0;
	}
	for(int x: order)
		cout << x+1 << " ";

	return 0;
}
