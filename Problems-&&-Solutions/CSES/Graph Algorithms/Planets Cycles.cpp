/*
Problem Statement: https://cses.fi/problemset/task/1751
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
// cr-->cycle root, cs-->cycle size
int n, q, t[mxN], vis[mxN], d[mxN], rt[mxN], cr[mxN], rp[mxN], dt, ds[mxN], de[mxN], cs[mxN];
vector<int> adj[mxN], cyc;

void dfs(int u) {
	ds[u]=dt++;
	for(int v: adj[u]) {
		if(rt[v]^v) {
			d[v]=d[u]+1;
			rt[v]=rt[u];
			cr[v]=cr[u];
			dfs(v);
		}
	}
	de[u]=dt;
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> t[i], --t[i];
		adj[t[i]].push_back(i);
	}
	memset(rt, -1, 4*n);
	for(int i=0; i<n; ++i) {
		if(~rt[i])
			continue;
		int u=i;
		while(!vis[u]) {
			vis[u]=1;
			u=t[u];
		}
		while(!cyc.size()||u^cyc[0]) {
			rp[u]=cyc.size();
			cyc.push_back(u);
			rt[u]=u;
			cr[u]=i;
			u=t[u];
		}
		for(int ci: cyc)
			dt=0, dfs(ci), cs[ci]=cyc.size();
		cyc.clear();
	}
	for(int i=0; i<n; ++i)
		cout << d[i]+cs[rt[i]] << " ";
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
