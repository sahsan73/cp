/*
Problem Statement: https://www.spoj.com/problems/MST/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: PRIM'S ALGORITHM FOR MST
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e4;
int n, m, vis[mxN];
vector<ar<int, 2>> adj[mxN];

int main() {
	cin >> n >> m;
	for(int i=0, a, b, c; i<m; ++i) {
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}

	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({0, 0});
	ll ans=0;
	while(!pq.empty()) {
		ar<ll, 2> u=pq.top();
		pq.pop();
		if(vis[u[1]])
			continue;
		for(ar<int, 2> v: adj[u[1]]) {
			if(!vis[v[1]])
				pq.push({v[0], v[1]});
		}

		ans+=u[0];
		vis[u[1]]=1;
	}
	cout << ans;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KRUSKAL'S ALGORITHM FOR MST
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e4;
int n, m, p[mxN], r[mxN];
vector<ar<int, 3>> e;

int find(int u) {
	return u^p[u]?p[u]=find(p[u]):u;
}

bool join(int u, int v) {
	if((u=find(u))==(v=find(v)))
		return 0;
	if(r[u]<r[v])
		swap(u, v);
	p[v]=u;
	if(r[u]==r[v])
		++r[u];
	return 1;
}

int main() {
	cin >> n >> m;
	for(int i=0, a, b, c; i<m; ++i) {
		cin >> a >> b >> c, --a, --b;
		e.push_back({c, a, b});
	}

	sort(e.begin(), e.end());
	iota(p, p+n, 0);
	ll ans=0;
	for(int i=0; i<m; ++i) {
		if(join(e[i][1], e[i][2]))
			ans+=e[i][0];
	}
	cout << ans;

	return 0;
}
