/*
Problem Statement: https://cses.fi/problemset/task/1687/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Iterative Implementation

This problem has a specific condition 1 <= ei <= i-1 ---> This implies that we can use
iterative implementation of dfs.
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, q, p[mxN], d[mxN], anc[mxN][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	memset(anc[0], -1, sizeof(anc[0]));
	for(int i=1; i<n; ++i)
		cin >> anc[i][0], --anc[i][0];

	// no ancestor(s) for the boss, which is why started with i=1
	for(int i=1; i<n; ++i)
		for(int j=1; j<20; ++j)
			anc[i][j]=~anc[i][j-1]?anc[anc[i][j-1]][j-1]:-1;

	while(q--) {
		int x, k;
		cin >> x >> k, --x;
		for(int j=19; ~j; --j)
			if(k&1<<j)
				x=~x?anc[x][j]:-1;
		cout << (~x?x+1:x) << "\n";
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
Iterative Implementation of bfs approach
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, q, p[mxN], d[mxN], anc[mxN][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	memset(anc[0], -1, sizeof(anc[0]));
	for(int i=1; i<n; ++i)
		cin >> anc[i][0], --anc[i][0];

	for(int j=1; j<20; ++j) {
		// no ancestor(s) for the boss, which is why started with i=1
		for(int i=1; i<n; ++i)
			anc[i][j]=~anc[i][j-1]?anc[anc[i][j-1]][j-1]:-1;
	}

	while(q--) {
		int x, k;
		cin >> x >> k, --x;
		for(int j=19; ~j; --j)
			if(k&1<<j)
				x=~x?anc[x][j]:-1;
		cout << (~x?x+1:x) << "\n";
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* APPROACH: DFS */
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, q, p[mxN], d[mxN], anc[mxN][20];
vector<int> adj[mxN];

void dfs(int u=0) {
	anc[u][0]=p[u];
	for(int j=1; j<20; ++j)
		anc[u][j]=~anc[u][j-1]?anc[anc[u][j-1]][j-1]:-1;
	for(int v: adj[u]) {
		if(v==p[u])
			continue;
		d[v]=d[u]+1;
		dfs(v);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	memset(p, -1, sizeof(p));
	for(int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	dfs();

	while(q--) {
		int x, k;
		cin >> x >> k, --x;
		if(k<=d[x]) {
			for(int j=19; ~j; --j)
				if(k&1<<j)
					x=anc[x][j];
			cout << x+1 << "\n";
		} else
			cout << "-1\n";
	}

	return 0;
}
