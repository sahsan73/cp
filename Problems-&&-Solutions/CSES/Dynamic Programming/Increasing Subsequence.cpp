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

const int mxN=2e5;
int n, a[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	vector<int> sub{a[0]};
	for(int i=1; i<n; ++i) {
		if(a[i]>sub.back()) {
			sub.push_back(a[i]);
		} else {
			int idx=lower_bound(sub.begin(), sub.end(), a[i])-sub.begin();
			sub[idx]=a[i];
		}
	}
	cout << sub.size();

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

const int mxN=2e5;
int n, a[mxN], dp[mxN], ans;

struct FenTree {
	int a[mxN+1];

	void upd(int i, int x) {
		for(++i; i<=n; i+=i&-i)
			a[i]=max(a[i], x);
	}

	int qry(int i) {
		int r=0;
		for(++i; i>0; i-=i&-i)
			r=max(r, a[i]);
		return r;
	}
} ft;

int main() {
	cin >> n;
	vector<int> b(n);
	for(int i=0; i<n; ++i)
		cin >> a[i], b[i]=a[i];

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end()); // unique and sorted values of a
	
	for(int i=0; i<n; ++i) {
		int idx=lower_bound(b.begin(), b.end(), a[i])-b.begin();
		dp[i]=ft.qry(idx-1)+1;
		ft.upd(idx, dp[i]);

		ans=max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}

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

const int mxN=2e5;
int n, a[mxN], dp[mxN], ans;

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	std::fill(begin(dp), end(dp), 1);
	for(int i=1; i<n; ++i) {
		for(int j=0; j<i; ++j) {
			if(a[j]<a[i]) {
				dp[i]=max(dp[i], 1+dp[j]);
				ans=max(ans, dp[i]);
			}
		}
	}
	cout << ans;

	return 0;
}
