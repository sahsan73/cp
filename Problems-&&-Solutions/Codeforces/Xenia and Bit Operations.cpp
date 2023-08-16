/*
Problem Statement: https://codeforces.com/problemset/problem/339/D
*/

#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, m, a[mxN], st[4*mxN], f;

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1) {
	if(l2==r2) {
		st[i]=x;
		f=1;
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		upd(l1, x, 2*i, l2, m2);
	else
		upd(l1, x, 2*i+1, m2+1, r2);
	if(f)
		st[i]=st[2*i]|st[2*i+1];
	else
		st[i]=st[2*i]^st[2*i+1];
	f^=1;
}

int main() {
	cin >> n >> m;
	n=1<<n;
	for(int i=0; i<n; ++i)
		cin >> a[i], upd(i, a[i]);

	while(m--) {
		int p, b;
		cin >> p >> b, --p;
		upd(p, b);
		cout << st[1] << "\n";
	}

	return 0;
}
