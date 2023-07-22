/*
APPROACH: EULER TOUR
    - Suppose we have a tree: {{x1, x2}, {x1, x3}, {x3, x4}, {x3, x5}} and value at each node as: {a1, a2, a3, a4, a5}

    - Timeline/Timer:  0        1        2        3        4        5
          node enter:  x1      x2       x3       x4       x5
           node exit:                   x2                x4       x5/x3/x1

    - The core idea is, suppose we have any subtree x and its children are y and z, then all the nodes in y and z will
      contain the value of x subtree.

    - As we are using Fenwick Tree to store sum, if we are updating a value at index i, we are also updating [i....n] for all indices in prefix sum. For
      example, in our above case, when we are updating ds[x2] (=1) with value a2, we are updating other all (2, 3, 4, 5..) too which obviously not
      favorable since x3, x4, x5 nodes are not in the substree of x2.
                  Therefore we need to subtract the same value a2 which are NOT in the subtree of x2, and can simply be done with the statement
      "upd(de[x2], -a2)", it will reduce the same value a2 in all subtrees x3, x4, x5....

COMPLEXITY:
    - TC = O(q*logn)
    - SC = O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=2e5;
int n, q, d[mxN], ds[mxN], de[mxN], dt;
ll a[mxN], ft[mxN+1];
vt<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	ds[u]=dt++;
	for(int v: adj[u]) {
		if(v==p)
			continue;
		d[v]=d[u]+1;
		dfs(v, u);
	}
	de[u]=dt;
}

void upd(int i, ll x) {
	for(++i; i<=n; i+=i&-i)
		ft[i]+=x;
}

ll qry(int i) {
	ll r=0;
	for(++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs();
	for(int i=0; i<n; ++i)
		upd(ds[i], a[i]), upd(de[i], -a[i]);
	while(q--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			int s, x;
			cin >> s >> x, --s;
			upd(ds[s], x-a[s]);
			upd(de[s], a[s]-x);
			a[s]=x;
		} else {
			int s;
			cin >> s, --s;
			cout << qry(ds[s]) << "\n";
		}
	}

	return 0;
}
