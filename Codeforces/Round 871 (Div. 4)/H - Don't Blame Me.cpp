// Upsolved
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int INF=1e9+5;
const int mod=1e9+7;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, k;

void solve() {
	cin >> n >> k;
	vt<int> arr(n+1);
	for(int i=1; i<=n; ++i) cin >> arr[i];
	
	// dp[i][j]=no. of subsequences using the first i elements that have a total AND value of j
	// given that 0<=a[i]<=63, max(j)<=63
	int dp[n+1][64];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<(1<<6); ++j) {
			dp[i][j]+=dp[i-1][j]; // exclude the curr number
			if(dp[i][j]>=mod) dp[i][j]-=mod;

			dp[i][j&arr[i]]+=dp[i-1][j]; // include the curr number
			if(dp[i][j&arr[i]]>=mod) dp[i][j&arr[i]]-=mod;
		}

		// start a new subsequece with ith element
		dp[i][arr[i]]+=1;
		if(dp[i][arr[i]]>=mod) dp[i][arr[i]]-=mod;
	}

	int cnt=0;
	for(int j=0; j<(1<<6); ++j) {
		if(__builtin_popcount(j)==k)
			cnt=(cnt+dp[n][j])%mod;
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}
