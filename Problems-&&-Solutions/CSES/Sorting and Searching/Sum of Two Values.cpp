/*
Problem Statement: https://cses.fi/problemset/task/1640
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Using unordered_map with some hacks

TC = O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x, a[mxN];

void solve() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int y=uniform_int_distribution<int>(69, 69696969)(rng);

	unordered_map<int, int> mp;
	for(int i=0; i<n; ++i) {
		if(mp.count((x-a[i])^y)) {
			cout << mp[(x-a[i])^y]+1 << " " << i+1;
			return;
		}
		mp[a[i]^y]=i;
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
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x, a[mxN];

void solve() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	/*
	 * If you try to use unordered_map, you may get TLE. As because, in worst case, count
  	 * operation works in O(n) time.
	*/
	map<int, int> mp;
	for(int i=0; i<n; ++i) {
		if(mp.count(x-a[i])) {
			cout << mp[x-a[i]]+1 << " " << i+1;
			return;
		}
		mp[a[i]]=i;
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
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x;
ar<int, 2> a[mxN];

void solve() {
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i][0], a[i][1]=i+1;
	sort(a, a+n);
	for(int i=0, j=n-1; i<j;) {
		int s=a[i][0]+a[j][0];
		if(s==x) {
			cout << a[i][1] << " " << a[j][1];
			return;
		}
		if(s<x)
			++i;
		else
			--j;
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
