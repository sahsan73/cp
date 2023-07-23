#include <bits/stdc++.h>
using namespace std;

#define ar array
const int mxN=2e5;
int n, d[mxN], ans[mxN]; // d[u]-->height of a node u
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
		d[u]=max(d[u], d[v]+1);
	}
}

void dfs2(int u=0, int p=-1, int pd=0) {
	//cout << u << ": " << p << ", " << pd << "\n";
	ans[u]=max(d[u], pd);
	vector<ar<int, 2>> w{{pd, -1}};
	for(int v: adj[u]) {
		if(v==p)
			continue;
		w.push_back({d[v]+1, v});
	}
	sort(w.begin(), w.end(), greater<ar<int, 2>>());
	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs2(v, u, w[0][1]==v?w[1][0]+1:w[0][0]+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1, a, b; i<n; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs();
	//cout << "heights:......." << "\n";
	//for(int i=0; i<n; ++i)
		//cout << i << ": " << d[i] << "\n";
	//cout << "===============================" << "\n";
	dfs2();
	//cout << "===============================" << "\n";
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";

	return 0;
}
