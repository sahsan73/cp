#include <bits/stdc++.h>
using namespace std;

char s[9];

int main() {
	cin >> s;

	int b1=-1, b2=-1, r1=-1, r2=-1;
	for(int i=0; i<8; ++i) {
		if(s[i]=='B') {
			if(b1!=-1) b2=i+1;
			else b1=i+1;
		}

		if(s[i]=='R') {
			if(r1!=-1) r2=i+1;
			else r1=i+1;
		}
	}

	bool c1=0;
	if(((b1&1)&&(b2%2==0))||((b1%2==0)&&(b2&1))) c1=1;
	bool c2=0;
	for(int i=r1-1; i<r2; ++i) {
		if(s[i]=='K') c2=1;
	}

	if(c1&&c2) cout << "Yes" << '\n';
	else cout << "No" << '\n';

	return 0;
}
