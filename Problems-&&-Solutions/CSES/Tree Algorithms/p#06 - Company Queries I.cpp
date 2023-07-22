#include <bits/stdc++.h>
using namespace std;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

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

int qry(int u, int k) {
	if(d[u]<k) return -1;
	for(int j=19; ~j; --j) {
		if(k&(1<<j))
			u=anc[u][j];
	}
	return u+1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i=1, p; i<n; ++i) {
		cin >> p, --p;
		adj[p].pb(i);
	}

	dfs();
	while(q--) {
		int x, k;
		cin >> x >> k, --x; 
		cout << qry(x, k) << "\n";
	}

	return 0;
}
