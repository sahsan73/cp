/*
Problem Statement: https://cses.fi/problemset/task/1643
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: KADANE'S ALGORITHM
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5;
int n;
ll x[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];

	ll s=x[0], a=x[0];
	for(int i=1; i<n; ++i) {
		s=max(s+x[i], x[i]);
		a=max(a, s);
	}
	cout << a;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: D&C
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n;
ll x[mxN];

ll dfs(int i, int j) {
	if(i==j)
		return x[i];
	int m=(i+j)/2;
	ll ls=dfs(i, m);
	ll rs=dfs(m+1, j);

	ll cs=-1e18, s=0; // cs --> crossing sum (left)
	for(int k=m; k>=i; --k) {
		s+=x[k];
		cs=max(cs, s);
	}
	ll cs2=-1e18, s2=0; // crossing sum (right)
	for(int k=m+1; k<=j; ++k) {
		s2+=x[k];
		cs2=max(cs2, s2);
	}
	return max({ls, (cs+cs2), rs});
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];
	cout << dfs(0, n-1);
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
