/*
Problem Statement: https://cses.fi/problemset/task/1671
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m;
vector<ar<int, 2>> adj[mxN];
ll d[mxN];

int main() {
	cin >> n >> m;
	for(int i=0, a, b, c; i<m; ++i) {
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({c, b});
	}

	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({0, 0});
	memset(d, 0x3f, sizeof(d));
	d[0]=0;
	while(!pq.empty()) {
		ar<ll, 2> u=pq.top();
		pq.pop();
		if(u[0]>d[u[1]])
			continue;
		for(ar<int, 2> v: adj[u[1]]) {
			if(v[0]+u[0]<d[v[1]]) {
				d[v[1]]=v[0]+u[0];
				pq.push({d[v[1]], v[1]});
			}
		}
	}
	for(int i=0; i<n; ++i)
		cout << d[i] << " ";
	
	return 0;
}
