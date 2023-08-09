/*
Problem Statement: https://cses.fi/problemset/task/1675
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: PRIM'S ALGORITHM FOR MST
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5, mxM=2e5;
int n, m, vis[mxN];
vector<ar<ll, 2>> adj[mxN];

int main() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
	pq.push({0, 0});
	ll ans=0;
	int cnt=0;
	while(!pq.empty()) {
		ar<ll, 2> u=pq.top();
		pq.pop();
		if(vis[u[1]])
			continue;
		for(ar<ll, 2> v: adj[u[1]]) {
			if(!vis[v[1]])
				pq.push({v[0], v[1]});
		}
		ans+=u[0];
		vis[u[1]]=1;
		++cnt;
	}
	if(cnt<n-1)
		cout << "IMPOSSIBLE";
	else
		cout << ans;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KRUSKAL'S ALGORITHM FOR MST
    - Disjoint Set Union (DSU)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e5, mxM=2e5;
int n, m, p[mxN], r[mxN];
ar<ll, 3> e[mxM];

int find(int u) {
	if(u==p[u])
		return u;
	return p[u]=find(p[u]);
}

bool join(int u, int v) {
	u=find(u), v=find(v);
	if(u==v)
		return false;

	if(r[u]<r[v])
		swap(u, v);
	p[v]=u;
	if(r[u]==r[v])
		++r[u];
	return true;
}

int main() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> e[i][1] >> e[i][2] >> e[i][0];
		--e[i][1], --e[i][2];
	}

	sort(e, e+m);
	std::iota(p, p+n, 0);
	ll ans=0;
	int cnt=0;
	for(int i=0; i<m; ++i) {
		if(join(e[i][1], e[i][2]))
			ans+=e[i][0], ++cnt;
	}
	if(cnt<n-1)
		cout << "IMPOSSIBLE";
	else
		cout << ans;

	return 0;
}
