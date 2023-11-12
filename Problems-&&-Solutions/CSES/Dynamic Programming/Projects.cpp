/*
Problem Statement: https://cses.fi/problemset/task/1140

References:
    1) Algorithm Design - Jon Kleinberg & Eva Tardos
    2) https://ocw.mit.edu/courses/6-046j-design-and-analysis-of-algorithms-spring-2015/resources/lecture-1-course-overview-interval-scheduling/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Iterative Implementation */
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, p[mxN];
ar<int, 3> a[mxN+1];
ll dp[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1; i<=n; ++i)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	sort(a, a+n+1, [](ar<int, 3> t1, ar<int, 3> t2){
		return t1[1]<t2[1];
	});

	for(int i=1; i<=n; ++i) {
		// j==p[i]
		int j=lower_bound(a, a+n+1, a[i][0], [](ar<int, 3> t, int x){
			return t[1]<x;
		})-begin(a)-1;
		
		// a[i][2]+dp[j] --> including current task
		// dp[i-1] --> excluding current task
		dp[i]=max(a[i][2]+dp[j], dp[i-1]);
	}
	cout << dp[n];

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Recursive Implementation */
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, p[mxN];
ar<int, 3> a[mxN];
ll dp[mxN];

ll dfs(int i=n-1) {
	if(i<0)
		return 0;
	if(~dp[i])
		return dp[i];
	return dp[i]=max(a[i][2]+dfs(p[i]), dfs(i-1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	// sort the task(interval) by their finishing time
	sort(a, a+n, [](ar<int, 3> t1, ar<int, 3> t2){
		return t1[1]<t2[1];
	});

	/* We define p[i], for ith interval, to be the largest
	 * index j<i such that intervals j and i are disjoint.
	 */
	for(int i=0; i<n; ++i) {
		auto it=lower_bound(a, a+n, a[i][0], [](ar<int, 3> t, int x){
			return t[1]<x;
		});
		if(it==begin(a))
			p[i]=-1;
		else
			p[i]=it-begin(a)-1;
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs();

	return 0;
}
