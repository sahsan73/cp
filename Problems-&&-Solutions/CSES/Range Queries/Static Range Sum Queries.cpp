/*
Problem Statement: https://cses.fi/problemset/task/1646
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5;
int n, q, x[mxN+1];
ll s[mxN+1];

int main() {
	cin >> n >> q;
	for(int i=1; i<=n; ++i)
		cin >> x[i];
	
	for(int i=1; i<=n; ++i)
		s[i]=s[i-1]+x[i];
	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << (s[b]-s[a-1]) << "\n";
	}

	return 0;
}

