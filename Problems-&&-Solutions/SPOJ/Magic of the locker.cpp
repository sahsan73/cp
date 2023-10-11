/*
Problem Statement: https://www.spoj.com/problems/LOCKER/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll M=1e9+7;
#define ar array

// binary power
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

void solve() {
	ll n;
	cin >> n;
	if(n<3) {
		cout << n << "\n";
		return;
	}
	ll a=3, b=n/3, r=n%3;
	ll ans=-1;
	if(r==1)
		ans=(bp(a, b-1)*4)%M;
	else if(r==2)
		ans=(bp(a, b)*2)%M;
	else
		ans=bp(a, b);
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
