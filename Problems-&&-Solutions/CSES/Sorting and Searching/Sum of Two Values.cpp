/*
Problem Statement: https://cses.fi/problemset/task/1640
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n;
ll x;
ar<ll, 2> a[mxN];

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i][0], a[i][1]=i+1;

	/*
	 * If you try to use unordered_map, you will get TLE. As because, in worst case, count
  	 * operation works in O(n) time.
	*/
	map<ll, ll> mp;
	for(int i=0; i<n; ++i) {
		if(mp.count(x-a[i][0])) {
			cout << mp[x-a[i][0]] << " " << a[i][1];
			return 0;
		}
		mp[a[i][0]]=a[i][1];
	}
	cout << "IMPOSSIBLE";

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n;
ll x;
ar<ll, 2> a[mxN];

int main() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i][0], a[i][1]=i+1;

	sort(a, a+n);
	int i=0, j=n-1;
	while(i<j) {
		ll s=a[i][0]+a[j][0];
		if(s==x) {
			cout << a[i][1] << " " << a[j][1];
			return 0;
		}

		if(s<x)
			++i;
		else
			--j;
	}
	cout << "IMPOSSIBLE";

	return 0;
}
