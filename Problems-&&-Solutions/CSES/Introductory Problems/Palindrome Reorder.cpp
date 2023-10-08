/*
Problem Statement: https://cses.fi/problemset/task/1755/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

void solve() {
	string s;
	cin >> s;
	int dp[26] = {};
	for(int i=0; i<s.size(); ++i)
		++dp[s[i]-'A'];
	int cnt=0;
	for(int i=0; i<26; ++i)
		cnt+=dp[i]&1;
	if(cnt>1) {
		cout << "NO SOLUTION";
		return;
	}

	string s1, s2, s3;
	for(int i=0; i<26; ++i) {
		if(dp[i]&1) {
			s3=string(dp[i], i+'A');
			continue;
		}
		s1+=string(dp[i]/2, i+'A');
	}
	s2=s1;
	reverse(s2.begin(), s2.end());
	cout << (s1+s3+s2);
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
