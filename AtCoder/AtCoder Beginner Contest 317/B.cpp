#include <bits/stdc++.h>
using namespace std;

int n, a[100];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	sort(a, a+n);
	for(int i=0; i<n-1; ++i) {
		if(a[i]+1^a[i+1]) {
			cout << a[i]+1;
			return 0;
		}
	}
	if(a[0]>1)
		cout << a[0]-1;
	else
		cout << a[n-1]+1;

	return 0;
}
