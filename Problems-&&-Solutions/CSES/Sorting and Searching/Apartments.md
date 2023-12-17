# Apartments
Problem Statement: <https://cses.fi/problemset/task/1084>   

Explanation-   
![Problem explanation illustrations](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/sorting-and-searching-apartments.png)


# Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, m, k, a[mxN], b[mxN];

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    for(int i=0; i<m; ++i)
        cin >> b[i];
    
    sort(a, a+n);
    sort(b, b+m);
    int cnt=0;
    for(int i=0, j=0; i<n&&j<m;) {
        if(a[i]-k<=b[j]&&b[j]<=a[i]+k)
            ++cnt, ++i, ++j;
        else if(b[j]<a[i]-k)
            ++j;
        else
            ++i;
    }
    cout << cnt;
    
    return 0;
}
```
