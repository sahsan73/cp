/*
Problem Statement: https://cses.fi/problemset/task/1195
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m;
ll d1[mxN], d2[mxN];
vector<ar<ll, 2>> adj[mxN], radj[mxN];

void solve(int s, vector<ar<ll, 2>> adj[mxN], ll d[mxN]) {
	memset(d, 0x3f, sizeof(d1));
	d[s]=0;
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({0, s});
	while(!pq.empty()) {
		ar<ll, 2> u=pq.top(); // u[0]-->price/cost/weight/dist, u[1]-->node
		pq.pop();
		if(u[0]>d[u[1]]) // IMPORTANT!!
			continue;

		for(ar<ll, 2> v: adj[u[1]]) { // v[0]-->edge price/cost/weight/dist, v[1]-->adjacent node
			if(u[0]+v[0]<d[v[1]]) {
				d[v[1]]=u[0]+v[0];
				pq.push({d[v[1]], v[1]});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0, a, b, w; i<m; ++i) {
		cin >> a >> b >> w, --a, --b;
		adj[a].push_back({w, b});
		radj[b].push_back({w, a});
	}

	solve(0, adj, d1);
	solve(n-1, radj, d2);

	ll ans=1e18;
	for(int u=0; u<n; ++u) {
		for(ar<ll, 2> it: adj[u]) {
			ll w=it[0], v=it[1];
			ans=min(ans, d1[u]+w/2+d2[v]);
		}
	}
	cout << ans;
	
	return 0;
}
