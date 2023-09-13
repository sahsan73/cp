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

const int mxN=2e5;
int n;
ll x[mxN];

ll dfs(int l=0, int r=n-1) {
	if(l==r)
		return x[l];
	
	int m=(l+r)/2;
	ll ml=dfs(l, m); // maximum left subarray sum
	ll mr=dfs(m+1, r); // maximum right subarray sum

	// crossing the midpoint
	ll s=0LL, ls=-1e18;
	for(int i=m; i>=l; --i)
		s+=x[i], ls=max(ls, s);
	s=0LL; ll rs=-1e18;
	for(int i=m+1; i<=r; ++i)
		s+=x[i], rs=max(rs, s);
	return max({ml, mr, ls+rs});
}

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];

	cout << dfs();

	return 0;
}
