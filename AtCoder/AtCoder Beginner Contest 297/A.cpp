#include <bits/stdc++.h>
using namespace std;

int n, d;

int main() {
	cin >> n >> d;
	vector<int> arr(n);
	for(int i=0; i<n; ++i) cin >> arr[i];

	for(int i=1; i<n; ++i) {
		if(arr[i]-arr[i-1]<=d) {
			cout << arr[i] << '\n';
			return 0;
		}
	}
	cout << (-1) << '\n';


	return 0;
}
