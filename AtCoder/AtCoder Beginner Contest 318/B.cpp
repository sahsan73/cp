#include <bits/stdc++.h>
using namespace std;

int n, s[101][101];

int main() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d, --b, --d;
		for(int y=c; y<=d; ++y)
			for(int x=a; x<=b; ++x)
				s[y][x]=1;
	}
	
	int a=0;
	for(int i=0; i<=100; ++i)
		for(int j=0; j<=100; ++j)
			a+=s[i][j];
	cout << a;

	return 0;
}
