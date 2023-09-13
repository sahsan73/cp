/*
Problem Statement: https://cses.fi/problemset/task/1642
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3;
int n;
ll x;
ar<ll, 2> a[mxN];

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i][0], a[i][1]=i+1;

	sort(a, a+n);
	
	for(int i=0; i<n-3; ++i) {
		if(i&&a[i]==a[i-1])
			continue;
		for(int j=i+1; j<n-2; ++j) {
			if(j>i+1&&a[j]==a[j-1])
				continue;

			int p=j+1, q=n-1;
			while(p<q) {
				ll s=a[i][0]+a[j][0]+a[p][0]+a[q][0];
				if(s==x) {
					cout << a[i][1] << " " << a[j][1] << " " << a[p][1] << " " << a[q][1];
					return 0;
				}

				if(s<x)
					++p;
				else
					--q;
			}
		}
	}
	cout << "IMPOSSIBLE";

	return 0;
}
