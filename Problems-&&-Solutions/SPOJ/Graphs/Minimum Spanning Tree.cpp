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
	for(int i, u, v, k; i<m; ++i) {
		cin >> u >> v >> k, --u, --v;
		adj[u].push_back({k, v});
		adj[v].push_back({k, u});
	}

	priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
	pq.push({0, 0});
	ll a=0;
	while(!pq.empty()) {
		ar<int, 2> u=pq.top();
		pq.pop();
		if(vis[u[1]])
			continue;
		for(ar<int, 2> v: adj[u[1]]) {
			if(!vis[v[1]])
				pq.push({v[0], v[1]});
		}
		a+=(ll)u[0];
		vis[u[1]]=1;
	}
	cout << a;

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
int n, m, p[mxN], s[mxN];
vector<ar<int, 3>> e;

int find(int u) {
	return u^p[u]?p[u]=find(p[u]):u;
}

bool join(int u, int v) {
	if((u=find(u))==(v=find(v)))
		return 0;
	if(s[u]<s[v])
		swap(u, v);
	p[v]=u;
	s[u]+=s[v];
	return 1;
}

int main() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int u, v, k;
		cin >> u >> v >> k, --u, --v;
		e.push_back({u, v, k});
	}

	sort(e.begin(), e.end(), [](auto &e1, auto &e2){
		return e1[2]<e2[2];
	});
	iota(p, p+n, 0);
	fill(s, s+n, 1);
	ll a=0;
	for(int i=0; i<m; ++i) {
		if(join(e[i][0], e[i][1]))
			a+=(ll)e[i][2];
	}
	cout << a;

	return 0;
}
