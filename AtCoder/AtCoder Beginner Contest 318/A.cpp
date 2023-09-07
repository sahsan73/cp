#include <bits/stdc++.h>
using namespace std;

int n, m, p;

int main() {
	cin >> n >> m >> p;
	int a=(n>=m)?1:0;
	a+=(n-m)/p;
	cout << a;

	return 0;
}
