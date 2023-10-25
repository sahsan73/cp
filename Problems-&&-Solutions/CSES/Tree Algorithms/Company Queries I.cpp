/*
Problem Statement: https://cses.fi/problemset/task/1687/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, q, e[mxN], anc[mxN][20];

void solve() {
	cin >> n >> q;
	memset(anc, -1, sizeof(anc));
	for(int i=1; i<n; ++i) {
		cin >> e[i], --e[i];
		anc[i][0]=e[i];
	}
	for(int j=1; j<20; ++j)
		for(int i=1; i<n; ++i)
			anc[i][j]=~anc[i][j-1]?anc[anc[i][j-1]][j-1]:-1;
	while(q--) {
		int x, k;
		cin >> x >> k, --x;
		for(int j=19; ~j; --j)
			if((1<<j)&k)
				x=~x?anc[x][j]:-1;
		cout << (~x?x+1:x) << "\n";
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, q, d[mxN], e[mxN], anc[mxN][20];
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

void solve() {
	cin >> n >> q;
	for(int i=1; i<n; ++i) {
		cin >> e[i], --e[i];
		adj[e[i]].push_back(i);
	}
	dfs();
	while(q--) {
		int x, k;
		cin >> x >> k, --x;
		if(k>d[x]) {
			cout << "-1\n";
		} else {
			for(int j=19; ~j; --j)
				if((1<<j)&k)
					x=anc[x][j];
			cout << x+1 << "\n";
		}
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
