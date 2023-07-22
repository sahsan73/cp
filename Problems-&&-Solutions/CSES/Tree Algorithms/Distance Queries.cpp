#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, q, d[mxN], anc[mxN][20];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	anc[u][0]=p;
	for(int j=1; j<20; ++j)
		anc[u][j]=~anc[u][j-1]?anc[anc[u][j-1]][j-1]:-1;
	for(int v: adj[u]) {
		if(v==p)
			continue;
		d[v]=d[u]+1;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if(d[u]<d[v])
		swap(u, v);
	int diff=d[u]-d[v];
	for(int j=19; ~j; --j) {
		if(diff&(1<<j))
			u=anc[u][j];
	}
	if(u==v) return u; // IMPORTANT
	
	// now both u and v are at the same level
	for(int j=19; ~j; --j) {
		if(anc[u][j]^anc[v][j]) {
			u=anc[u][j];
			v=anc[v][j];
		}
	}
	return anc[u][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i=1, a, b; i<n; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs();
	while(q--) {
		int a, b;
		cin >> a >> b, --a, --b;
		cout << (d[a]+d[b]-2*d[lca(a, b)]) << "\n";
	}

	return 0;
}
