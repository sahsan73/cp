#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5;
int n, m;
ll d[mxN];
vector<ar<ll, 2>> adj[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0, a, b, w; i<m; ++i) {
		cin >> a >> b >> w, --a, --b;
		adj[a].push_back({w, b});
	}

	memset(d, 0x3f, sizeof(d));
	d[0]=0;
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({0, 0});
	while(!pq.empty()) {
		ar<ll, 2> u=pq.top();
		pq.pop();
		if(u[0]>d[u[1]])
			continue;

		for(ar<ll, 2> v: adj[u[1]]) {
			if(u[0]+v[0]<d[v[1]]) {
				d[v[1]]=u[0]+v[0];
				pq.push({d[v[1]], v[1]});
			}
		}
	}

	for(int i=0; i<n; ++i)
		cout << d[i] << " ";
	
	return 0;
}
