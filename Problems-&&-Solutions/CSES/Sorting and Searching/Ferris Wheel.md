# Ferris Wheel
Problem Statement: <https://cses.fi/problemset/task/1090>   

Explanation-   
![Problem explanation](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/sorting-and-searching-ferris-wheel.png)   


### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, x, p[mxN];

int main() {
    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> p[i];
    
    sort(p, p+n);
    int cnt=0;
    for(int i=0, j=n-1; i<=j; --j) {
        if(p[i]+p[j]<=x)
            ++i;
        ++cnt;
    }
    cout << cnt;
    
    return 0;
}
```
