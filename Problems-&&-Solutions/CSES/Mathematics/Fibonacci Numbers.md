# Fibonacci Numbers
Problem Statement: <https://cses.fi/problemset/task/1722>   

The Problem asked us to compute $n^{th}$ fibonacci number. Now, if n is small (e.g., $<=10^6$) then we can easily use $O(n)$ dynamic programming solution. But, if $n$ is
very large (for e.g., $10^{18}$ we need to use **Matrix Exponentiation**.   

![Matrix recurrence relation](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/mathematics-fibonacci-numbers-recurrence-relations.png)   

**_Note:_** If you notice that, the base case $F(2)$ was taken to terminate the recurrence relation, we'll disuss later, **why??**   

### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int M=1e9+7;
ll n;

void multiply(ll a[2][2], ll b[2][2]) {
	ll c[2][2]={}; // auxiliary matrix
	for(int i=0; i<2; ++i)
		for(int j=0; j<2; ++j)
			for(int k=0; k<2; ++k)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%M;
	memcpy(a, c, sizeof(c));
}

int main() {
	cin >> n;
	if(n<=1) {
		cout << n;
		return 0;
	}

	n-=2;
	ll x[2][2]={{1, 1}, {1, 0}}, r[2][2]={{1, 0}, {0, 1}};
	while(n) {
		if(n&1)
			multiply(r, x);
		multiply(x, x);
		n>>=1;
	}
	cout << (r[0][0]+r[0][1])%M;

	return 0;
}
```
$Time Complexity \equiv O(logn)$
