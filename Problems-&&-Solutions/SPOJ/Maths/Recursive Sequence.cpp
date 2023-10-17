/*
Problem Statement: https://www.spoj.com/problems/SEQ/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int M=1e9;
int k;
ll b[10], c[10], n, x[10][10], z[10][10];

void multiply(ll y[10][10]) {
	memset(z, 0, sizeof(z)); // z-->auxiliary matrix
	for(int i=0; i<k; ++i)
		for(int j=0; j<k; ++j)
			for(int p=0; p<k; ++p)
				z[i][j]=(z[i][j]+(y[i][p]%M*x[p][j]%M)%M)%M;
	memcpy(y, z, sizeof(z));
}

void solve() {
	cin >> k;
	for(int i=0; i<k; ++i)
		cin >> b[i], b[i]%=M;
	for(int i=0; i<k; ++i)
		cin >> c[i];
	cin >> n;
	if(n<=k) {
		cout << b[--n] << "\n";
		return;
	}
	memset(x, 0, sizeof(x));
	for(int i=0; i<k; ++i) {
		x[0][i]=c[i];
		if(i)
			x[i][i-1]=1;
	}
	ll y[10][10];
	memset(y, 0, sizeof(y));
	// initially y should be identity matrix
	for(int i=0; i<k; ++i)
		y[i][i]=1;
	n-=k;
	while(n>0) {
		if(n&1)
			multiply(y);
		multiply(x);
		n>>=1;
	}
	ll ans=0;
	for(int i=0; i<k; ++i)
		ans=(ans+y[0][i]*b[k-i-1]%M)%M;
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
