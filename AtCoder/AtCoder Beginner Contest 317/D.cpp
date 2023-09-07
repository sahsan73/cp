/*
UPSOLVE
    - Tried bottom-up implementation
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxZ=1e5;
int n, tz;
ll dp[101][mxZ+1];
ar<int, 3> a[101];

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		tz+=a[i][2];
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0]=0;
	for(int i=1; i<=n; ++i) {
		for(int z=0; z<=tz; ++z) {
			ll exclude=dp[i-1][z];
			ll include=1e18;
			if(z>=a[i][2]) {
				if(a[i][0]>a[i][1])
					include=dp[i-1][z-a[i][2]];
				else
					include=(a[i][1]-a[i][0]+1)/2+dp[i-1][z-a[i][2]];
			}
			dp[i][z]=min(exclude, include);
		}
	}
	ll ans=1e18;
	for(int z=(tz+1)/2; z<=tz; ++z)
		ans=min(ans, dp[n][z]);
	cout << ans;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
DURING CONTEST
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxZ=1e5;
int n, tz;
ll dp[100][mxZ+1];
ar<int, 3> a[100];

ll dfs(int i=0, int z=0) {
	if(z>=(tz+1)/2)
		return 0;
	if(i>=n)
		return 1e18;
	if(~dp[i][z])
		return dp[i][z];

	ll exclude=dfs(i+1, z);
	ll include=(a[i][0]>a[i][1])?dfs(i+1, z+a[i][2]):(a[i][1]-a[i][0]+1)/2+dfs(i+1, z+a[i][2]);
	return dp[i][z]=min(exclude, include);
}

int main() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		tz+=a[i][2];
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs() << "\n";

	return 0;
}
