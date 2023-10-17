/*
Problem Statement: https://cses.fi/problemset/task/1722
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int M=1e9+7;
ll n, x[2][2]={{1, 1}, {1, 0}}, z[2][2];

void multiply(ll y[2][2]) {
	memset(z, 0, sizeof(z));
	for(int i=0; i<2; ++i)
		for(int j=0; j<2; ++j)
			for(int k=0; k<2; ++k)
				z[i][j]=(z[i][j]+(y[i][k]*x[k][j])%M)%M;
	memcpy(y, z, sizeof(z));
}

void solve() {
	cin >> n;
	ll y[2][2]={{}};
	y[0][0]=y[1][1]=1;
	while(n>0) {
		if(n&1)
			multiply(y);
		multiply(x);
		n>>=1;
	}
	cout << y[0][1];
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
