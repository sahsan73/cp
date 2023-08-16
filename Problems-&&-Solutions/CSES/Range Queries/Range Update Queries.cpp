/*
Problem Statement: https://cses.fi/problemset/task/1651
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5;
int n, q;
ll x[mxN];
struct {
	ll s, lz;
} st[4*mxN];

void app(int i, ll x, int l2, int r2) {
	st[i].s+=x*(r2-l2+1);
	st[i].lz+=x;
}

void push(int i, int l2, int m2, int r2) {
	app(2*i, st[i].lz, l2, m2);
	app(2*i+1, st[i].lz, m2+1, r2);
	st[i].lz=0;
}

void upd(int l1, ll x, int i=1, int l2=0, int r2=n-1) {
	if(l2==r2) {
		st[i].s=x;
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		upd(l1, x, 2*i, l2, m2);
	else
		upd(l1, x, 2*i+1, m2+1, r2);
	st[i].s=st[2*i].s+st[2*i+1].s;
}

ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
	if(l2>r1||r2<l1)
		return 0;
	if(l2>=l1&&r2<=r1)
		return st[i].s;
	int m2=(l2+r2)/2;
	push(i, l2, m2, r2);
	return qry(l1, r1, 2*i, l2, m2)+qry(l1, r1, 2*i+1, m2+1, r2);
}

void upd2(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-1) {
	if(l2>r1||r2<l1)
		return;
	if(l2>=l1&&r2<=r1) {
		app(i, x, l2, r2);
		return;
	}
	int m2=(l2+r2)/2;
	push(i, l2, m2, r2);
	upd2(l1, r1, x, 2*i, l2, m2);
	upd2(l1, r1, x, 2*i+1, m2+1, r2);
	st[i].s=st[2*i].s+st[2*i+1].s;
}

int main() {
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> x[i], upd(i, x[i]);

	while(q--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			ll a, b, u;
			cin >> a >> b >> u, --a, --b;
			upd2(a, b, u);
		} else {
			int k;
			cin >> k, --k;
			cout << qry(k, k) << "\n";
		}
	}

	return 0;
}
