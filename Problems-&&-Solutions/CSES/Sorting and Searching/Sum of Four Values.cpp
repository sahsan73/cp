/*
Problem Statement: https://cses.fi/problemset/task/1642
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
TC = O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3;
int n, x, a[mxN];

void solve() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	unordered_map<int, ar<int, 2>> mp;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			int t=x-(a[i]+a[j]);
			if(mp.count(t)) {
				cout << mp[t][0] << " " << mp[t][1] << " " << i+1 << " " << j+1;
				return;
			}
		}
		for(int j=0; j<i; ++j)
			mp[a[i]+a[j]]={i+1, j+1};
	}
	cout << "IMPOSSIBLE";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
TC = O(n^3)

VERDICT: AC
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3;
int n, x;
ar<int, 2> a[mxN];

void solve() {
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
			int k=j+1, l=n-1;
			while(k<l) {
				//if(k>j+1&&a[k]==a[k-1]) {
					//++k;
					//continue;
				//}
				ll s=a[i][0]+a[j][0]+a[k][0]+a[l][0];
				if(s==x) {
					cout << a[i][1] << " " << a[j][1] << " " << a[k][1] << " " << a[l][1];
				   return;	
				}
				if(s<x)
					++k;
				else
					--l;
			}
		}
	}
	cout << "IMPOSSIBLE";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
