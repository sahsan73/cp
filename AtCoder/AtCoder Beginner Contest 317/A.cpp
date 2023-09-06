#include <bits/stdc++.h>
using namespace std;

int n, h, x, p[101];

int main() {
	cin >> n >> h >> x;
	for(int i=1; i<=n; ++i)
		cin >> p[i];

	for(int i=1; i<=n; ++i) {
		if(h+p[i]>=x) {
			cout << i;
			exit(0);
		}
	}

	return 0;
}
