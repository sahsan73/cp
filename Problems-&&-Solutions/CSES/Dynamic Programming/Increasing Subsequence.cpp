/*
Problem Statement: https://cses.fi/problemset/task/1145
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BINARY SEARCH + DP

COMPLEXITY:
    - TC = O(nlogn)
    - SC = O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
#define ar array
 
const int mxN=2e5;
int n, x[mxN];
 
void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];
	vector<int> a={x[0]};
	for(int i=1; i<n; ++i) {
		if(x[i]>a.back())
			a.push_back(x[i]);
		else {
			auto idx=lower_bound(a.begin(), a.end(), x[i])-a.begin();
			a[idx]=x[i];
		}
	}
	cout << a.size();
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: FENWICK TREE + DP

COMPLEXITY:
    - TC = O(nlogn)
    - SC = O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x[mxN], ft[mxN+1];

void upd(int i, int x) {
	for(++i; i<=n; i+=i&-i)
		ft[i]=max(ft[i], x);
}

int qry(int i) {
	int res=0;
	for(++i; i>0; i-=i&-i)
		res=max(res, ft[i]);
	return res;
}

void solve() {
	cin >> n;
	vector<int> x2(n);
	for(int i=0; i<n; ++i)
		cin >> x[i], x2[i]=x[i];
	sort(x2.begin(), x2.end());
	x2.erase(unique(x2.begin(), x2.end()), x2.end());
	int a=0;
	for(int i=0; i<n; ++i) {
		int idx=lower_bound(x2.begin(), x2.end(), x[i])-x2.begin();
		int cnt=qry(idx-1)+1;
		upd(idx, cnt);
		a=max(a, cnt);
	}
	cout << a;
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
// P.S.: Personal opinion --> This doesn't make sense this way, we still have to use lower_bound then why don't simply use binary
// search method discussed above, this approach looks nice when we do not have duplicate items!

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up(Iteration + Tabulation)

COMPLEXITY:
    - TC = O(n^2)
    - SC = O(n)

VERDICT: TLE, However, this solution is AC in LeetCode as their constraints are very low
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x[mxN], dp[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];
	fill(dp, dp+n, 1);
	int a=1;
	for(int i=0; i<n; ++i)
		for(int j=0; j<i; ++j)
			if(x[j]<x[i]) {
				dp[i]=max(dp[i], 1+dp[j]);
				a=max(a, dp[i]);
			}
	cout << a;
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
