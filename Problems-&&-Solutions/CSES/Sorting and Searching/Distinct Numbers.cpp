/*
Problem Statement: https://cses.fi/problemset/task/1621
*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, x[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];

    /*
     * If you use unordered set, you'll get TLE. The reason is that in worst case,
     * insert operation works in O(n) time.
     * For more info:
     *     - visit: https://en.cppreference.com/w/cpp/container/unordered_set/insert
    */
	set<int> st;
	for(int i=0; i<n; ++i)
		st.insert(x[i]);
	cout << st.size();

	return 0;
}
