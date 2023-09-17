/*
Problem Statement: https://cses.fi/problemset/task/1074

Suppose we have some elements (p <-- array of elemenst) and we want them to be equal. Then the
median of the sorted array p, would be the length of each element.
    - This is a well known problem!
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5;
int n, p[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i];

	sort(p, p+n);
	ll x=p[n/2], a=0;
	for(int i=0; i<n; ++i)
		a+=abs(p[i]-x);
	cout << a;

	return 0;
}

// P.S.: Looking for its proof! will update once i get it...!
