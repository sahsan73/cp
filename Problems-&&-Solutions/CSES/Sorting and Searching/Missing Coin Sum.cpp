/*
Problem Statement: https://cses.fi/problemset/task/2183
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5;
int n, x[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];

	sort(x, x+n);

	ll s=0;
	for(int i=0; i<n; ++i) {
		if(x[i]>s+1)
			break;
		s+=x[i];
	}
	cout << s+1;

	return 0;
}
