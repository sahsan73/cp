/*
Problem Statement: https://cses.fi/problemset/task/1641
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=5e3;
int n;
ll x;
ar<ll, 2> a[mxN];

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i][0], a[i][1]=i+1;

	sort(a, a+n);
	
	for(int i=0; i<n-2; ++i) {
		int j=i+1, k=n-1;
		while(j<k) {
			ll s=a[i][0]+a[j][0]+a[k][0];
			if(s==x) {
				cout << a[i][1] << " " << a[j][1] << " " << a[k][1];
				return 0;
			}

			if(s<x)
				++j;
			else
				--k;
		}
	}
	cout << "IMPOSSIBLE";

	return 0;
}
