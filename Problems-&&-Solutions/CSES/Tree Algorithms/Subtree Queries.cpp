/*
Problem Statemtent: https://cses.fi/problemset/task/1137/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, q, a[mxN], dt, ds[mxN], de[mxN];
vector<int> adj[mxN];
ll ft[mxN+1];

void dfs(int u=0, int p=-1) {
	ds[u]=dt++;
	for(int v: adj[u])
		if(v^p)
			dfs(v, u);
	de[u]=dt;
}

void upd(int i, int x) {
	for(++i; i<=n; i+=i&-i)
		ft[i]+=x;
}

ll qry(int i) {
	ll r=0;
	for(; i>0; i-=i&-i)
		r+=ft[i];
	return r;
}

void solve() {
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=1, a, b; i<n; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs();
	for(int i=0; i<n; ++i)
		upd(ds[i], a[i]);

	while(q--) {
		int qt, s, x;
		cin >> qt;
		if(qt==1) {
			cin >> s >> x, --s;
			upd(ds[s], x-a[s]);
			a[s]=x;
		} else {
			int s;
			cin >> s, --s;
			cout << (qry(de[s])-qry(ds[s])) << "\n";
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
