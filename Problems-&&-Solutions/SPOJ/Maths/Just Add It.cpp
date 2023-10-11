/*
Problem Statement: https://www.spoj.com/problems/ZSUM/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll M=1e7+7;
#define ar array

ll n, k;

ll bp(ll a, ll b) {
	ll ans=1;
	while(b>0) {
		if(b&1)
			ans=(ans*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin>>n>>k&&n&&k) {
		cout << (2*bp(n-1, k)%M+bp(n, k)%M+2*bp(n-1, n-1)%M+bp(n, n)%M)%M << "\n";
	}
	return 0;
}
