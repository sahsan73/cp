#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		int s=0;
		for(int j=0, x; j<7; ++j)
			cin >> x, s+=x;
		cout << s << ' ';	
	}

	return 0;
}
