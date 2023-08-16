/*
Problem Statement: https://cses.fi/problemset/task/1647
*/

#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, q, x[mxN], st[4*mxN];

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
	if(l2==r2) {
		st[i]=x;
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		upd(l1, x, 2*i, l2, m2);
	else
		upd(l1, x, 2*i+1, m2+1, r2);
	st[i]=min(st[2*i], st[2*i+1]);
}

int qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
	if(l2>r1||r2<l1)
		return 1e9;
	if(l2>=l1&&r2<=r1)
		return st[i];
	int m2=(l2+r2)/2;
	return min(qry(l1, r1, 2*i, l2, m2), qry(l1, r1, 2*i+1, m2+1, r2));
}

int main() {
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> x[i], upd(i, x[i]);

	while(q--) {
		int a, b;
		cin >> a >> b, --a, --b;
		cout << qry(a, b) << "\n";
	}

	return 0;
}
