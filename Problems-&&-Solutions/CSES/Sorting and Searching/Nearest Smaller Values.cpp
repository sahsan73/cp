/*
Problem Statement: https://cses.fi/problemset/task/1645
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=2e5;
int n, x[mxN], a[mxN];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i];

	stack<ar<int, 2>> st;
	for(int i=0; i<n; ++i) {
		while(!st.empty()&&st.top()[0]>=x[i])
			st.pop();
		if(st.empty())
			a[i]=0;
		else
			a[i]=st.top()[1];

		st.push({x[i], i+1});
	}

	for(int i=0; i<n; ++i)
		cout << a[i] << " ";

	return 0;
}
