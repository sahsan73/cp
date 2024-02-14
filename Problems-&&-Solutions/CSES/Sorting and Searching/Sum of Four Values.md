# Sum of Four Values
Click [here](https://cses.fi/problemset/task/1642) to see the problem statement.   

### APPROACH - I
$TC\ \equiv\ O(n^3)$   

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3;
int n, x;
ar<int, 2> a[mxN];


int main() {
    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> a[i][0], a[i][1]=i+1;
    
    sort(a, a+n);
    for(int i=0; i<n-3; ++i) {
        if(i&&a[i][0]==a[i-1][0])
            continue;
        for(int j=i+1; j<n-2; ++j) {
            if(j>i+1&&a[j][0]==a[j-1][0])
                continue;
            int k=j+1, l=n-1;
            while(k<l) {
                if(k>j+1&&a[k][0]==a[k-1][0]) {
                    ++k;
                    continue;
                }
                ll s=a[i][0]+a[j][0]+a[k][0]+a[l][0];
                if(s==x) {
                    cout << a[i][1] << " " << a[j][1] << " " << a[k][1] << " " << a[l][1];
                    return 0;
                }
                
                if(s<x)
                    ++k;
                else
                    --l;
            }
        }
    }
    cout << "IMPOSSIBLE";
    
    return 0;
}
```

&nbsp;

### APPROACH - II
$TC\ \equiv\ O(n^2)$  

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define ar array

const int mxN=1e3;
int n, x, a[mxN];

int main() {
    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    
    unordered_map<int, ar<int, 2>> mp;
    for(int i=0; i<n-1; ++i) {
        for(int j=i+1; j<n; ++j) {
            int x2=x-(a[i]+a[j]);
            if(mp.count(x2)) {
                cout << mp[x2][0]+1 << " " << mp[x2][1]+1 << " "
                     << i+1 << " " << j+1;
                return 0;
            }
        }
        
        for(int j=0; j<i; ++j)
            mp[a[i]+a[j]]={j, i};
    }
    cout << "IMPOSSIBLE";
    
    return 0;
}
```
