#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5;
int n, d, p, f[mxN];

int main() {
	cin >> n >> d >> p;
	for(int i=0; i<n; ++i)
		cin >> f[i];

	sort(f, f+n, [](int x, int y){return x>y;});
	ll a=0LL, s=0LL;
	int cnt=0;
	for(int i=0; i<n; ++i) {
		++cnt;
		s+=f[i];
		if(cnt==d) {
			a+=(s>p)?p:s;
			cnt=0;
			s=0;
		}
	}
	a+=(s>p)?p:s;
	cout << a;

	return 0;
}
