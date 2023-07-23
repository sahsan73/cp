#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e5;
int n, q, ds[mxN], de[mxN], dt;
ll arr[mxN], ft[mxN+1];
vt<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	ds[u]=dt++;
	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
	}
	de[u]=dt;
}

void upd(int i, int x) {
	for(++i; i<=n; i+=i&-i)
		ft[i]+=x;
}

ll qry(int i) {
	ll r=0;
	for(; i; i-=i&-i)
		r+=ft[i];
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	for(int i=0, a, b; i<n-1; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs();
	for(int i=0; i<n; ++i)
		upd(ds[i], arr[i]);

	while(q--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			int s, x;
			cin >> s >> x, --s;
			upd(ds[s], x-arr[s]);
			arr[s]=x;
		} else {
			int s;
			cin >> s, --s;
			cout << qry(de[s])-qry(ds[s]) << '\n';
		}
	}

	return 0;
}
