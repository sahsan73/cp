#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
string s[100];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> s[i];

	auto check=[](string t) {
		int i=0, j=(int)t.size()-1;
		while(i<j) {
			if(t[i]!=t[j])
				return 0;
			++i, --j;
		}
		return 1;
	};

	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			if(check(s[i]+s[j])||check(s[j]+s[i])) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";

	return 0;
}
