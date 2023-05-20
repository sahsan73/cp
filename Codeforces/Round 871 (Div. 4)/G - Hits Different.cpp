#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int INF=1e9+5;

#define vt vector
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n;
ll ans[2000007];
ll arr[1500][1500]; // 2D prefix sum matrix

void solve() {
	cin >> n;
	cout << ans[n] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int curr=1;
	for(int i=1; i<1500; ++i) {
		for(int j=1, ii=i; j<=i; ++j, --ii) {
			arr[ii][j]=arr[ii][j-1]+arr[ii-1][j]-arr[ii-1][j-1]+(ll)curr*curr;
			ans[curr]=arr[ii][j];

			++curr;
		}
	}

	int t=1; cin >> t;
	while(t--) solve();
	return 0;
}

/*
P.S.: This is one of the interesting problems i have found, rotating the given image leads to a straight forward 2D prefix sum matrix!!
*/
