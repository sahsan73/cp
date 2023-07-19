/*
We can use "long long int" in C++ to represent 60 different colours, if ith is set, we i colour in our subtrr.
We use bitwise OR operation to merge colours (obtain different colours) from two different subtrees
    - st[i].cs = st[2*i].cs | st[2*i+1].cs;
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=4e5;
int n, m, c[mxN], ds[mxN], de[mxN], dt;
vt<int> adj[mxN];
struct {
	ll cs, lz; // cs --> colors set
} st[4*mxN];

void upd(int k, ll x, int i=1, int s=0, int e=n-1) {
	if(s==e) {
		st[i].cs=(1LL<<x);
		st[i].lz=0LL;
		return;
	}
	int m=(s+e)/2;
	if(k<=m)
		upd(k, x, 2*i, s, m);
	else
		upd(k, x, 2*i+1, m+1, e);
	st[i].cs=st[2*i].cs|st[2*i+1].cs;
}

void dfs(int u=0, int p=-1) {
	ds[u]=dt++;
	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
	}
	de[u]=dt;
}

void app(int i, ll x) {
	st[i].cs=(1LL<<x);
	st[i].lz=x;
}

void psh(int i) {
	if(st[i].lz==0LL)
		return;
	app(2*i, st[i].lz);
	app(2*i+1, st[i].lz);
	st[i].lz=0LL;
}

ll qry(int l, int r, int i=1, int s=0, int e=n-1) {
	if(s>r||e<l) return 0LL;
	if(s>=l&&e<=r) return st[i].cs;
	int m=(s+e)/2;
	psh(i);
	return qry(l, r, 2*i, s, m)|qry(l, r, 2*i+1, m+1, e);
}

void upd2(int l, int r, ll x, int i=1, int s=0, int e=n-1) {
	if(s>r||e<l) return;
	if(s>=l&&e<=r) {
		app(i, x);
		return;
	}
	int m=(s+e)/2;
	psh(i);
	upd2(l, r, x, 2*i, s, m);
	upd2(l, r, x, 2*i+1, m+1, e);
	st[i].cs=st[2*i].cs|st[2*i+1].cs;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	for(int i=0, x, y; i<n-1; ++i) {
		cin >> x >> y, --x, --y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs();
	for(int i=0; i<n; ++i)
		upd(ds[i], c[i]);

	while(m--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			int v, c;
			cin >> v >> c, --v;
			upd2(ds[v], de[v]-1, c);
		} else {
			int v;
			cin >> v, --v;
			cout << __builtin_popcountll(qry(ds[v], de[v]-1)) << "\n";
		}
	}

	return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Obviously, we cannot simply keep track of count of different colors, we need keep the colors also. Because, while adding the colors of
two or more different subtrees, we may end up counting duplicate colors.

So, at vertex u, we have an unordered set of colors --> which is different colors in a subtree u.

VERDICT: TLE
*/
#include <bits/stdc++.h>
using namespace std;
typedef unordered_set<int> us;

#define vt vector
#define sz(x) (x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int mxN=4e5;
int n, m, d1[mxN], ds[mxN], de[mxN], dt, c[mxN];
vt<int> adj[mxN];
struct {
	unordered_set<int> s; // colors
	int lz;
} st[4*mxN];

void dfs(int u=0, int p=-1) {
	ds[u]=dt++;
	for(int v: adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
	}
	de[u]=dt;
}

void merge(us &s1, us &s2, us &s3) {
	s1.clear();
	for(auto &x: s2) s1.insert(x);
	for(auto &x: s3) s1.insert(x);
}

void upd(int k, int x, int i=1, int s=0, int e=n-1) {
	if(s==e) {
		st[i].s.insert(x);
		st[i].lz=0;
		return;
	}
	int m=(s+e)/2;
	if(k<=m)
		upd(k, x, 2*i, s, m);
	else
		upd(k, x, 2*i+1, m+1, e);
	merge(st[i].s, st[2*i].s, st[2*i+1].s);
}

void app(int i, int x) {
	st[i].s.clear();
	st[i].s.insert(x);
	st[i].lz=x;
}

void psh(int i) {
	if(st[i].lz==0)
		return;
	app(2*i, st[i].lz);
	app(2*i+1, st[i].lz);
	st[i].lz=0;
}

us qry(int l, int r, int i=1, int s=0, int e=n-1) {
	if(s>r||e<l) return {};
	if(s>=l&&e<=r) return st[i].s;
	int m=(s+e)/2;
	psh(i);
	auto s1=qry(l, r, 2*i, s, m), s2=qry(l, r, 2*i+1, m+1, e);
	us res;
	merge(res, s1, s2);
	return res;
}

void upd2(int l, int r, int x, int i=1, int s=0, int e=n-1) {
	if(s>r||e<l) return;
	if(s>=l&&e<=r) {
		app(i, x);
		return;
	}
	int m=(s+e)/2;
	psh(i);
	upd2(l, r, x, 2*i, s, m);
	upd2(l, r, x, 2*i+1, m+1, e);
	merge(st[i].s, st[2*i].s, st[2*i+1].s);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	for(int i=0, x, y; i<n-1; ++i) {
		cin >> x >> y, --x, --y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs();
	for(int i=0; i<n; ++i)
		upd(ds[i], c[i]);
	
	while(m--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			int v, c;
			cin >> v >> c, --v;
			upd2(ds[v], de[v]-1, c);
		} else {
			int v;
			cin >> v, --v;
			cout << sz(qry(ds[v], de[v]-1)) << "\n";
		}
	}

	return 0;
}
