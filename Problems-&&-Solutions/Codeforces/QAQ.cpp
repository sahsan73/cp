/*
Problem Statement: https://codeforces.com/problemset/problem/894/A
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

char s[101];
int n, dp[101];

int main() {
	cin >> s;
	n=strlen(s);
	for(int i=1; i<=n; ++i)
		dp[i]=dp[i-1]+(s[i-1]=='Q');
	
	int cnt=0;
	for(int i=1; i<=n; ++i)
		if(s[i-1]=='A')
			cnt+=dp[i]*(dp[n]-dp[i]);
	cout << cnt;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BRUTE FORCE
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

char s[101];
int n, dp[4][101];

int main() {
	cin >> s;
	n=strlen(s);
	string t="QAQ";
	int cnt=0;
	for(int i=0; i<n-2; ++i)
		for(int j=i+1; j<n-1; ++j)
			for(int k=j+1; k<n; ++k) {
				string r=string()+s[i]+s[j]+s[k];
				if(r==t)
					++cnt;
			}
	
	cout << cnt;

	return 0;
}
