/*
Problem Statement: https://www.spoj.com/problems/ACODE/
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;

string s;
int n;
ll dp[10000];

ll dfs(int i) {
	if(i>=n)
		return 1;
	if(s[i]=='0')
		return 0;
	if(~dp[i])
		return dp[i];

	ll res=dfs(i+1);
	if((i+1<n)&&stoi(s.substr(i, 2))<=26)
		res+=dfs(i+2);
	return dp[i]=res;
}

int main() {
	while(cin>>s) {
		if(s=="0")
			break;
		n=(int)s.size();
		memset(dp, -1, sizeof(dp));
		cout << dfs(0) << "\n";
	}

	return 0;
}
