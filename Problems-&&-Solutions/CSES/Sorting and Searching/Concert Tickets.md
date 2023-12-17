# Concert Tickets
Problem Statement: <https://cses.fi/problemset/task/1091>   


### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=2e5;
int n, m;

int main() {
    cin >> n >> m;
    set<ar<int, 2>> st;
    for(int i=0, h; i<n; ++i) {
        cin >> h;
        /* To keep the duplicate items, if you think to use "multiset"
         * then you would have a problem with deleting an item. Because
         * multiset erase operation deletes all occurrences of an item.
         */
        st.insert({h, i});
    }
        
    for(int i=0, t; i<m; ++i) {
        cin >> t;
        /* The below works with both "upper_bound" and "lower_bound".The
         * comparison happens this way -> if first element equals, the
         * second element of array will be compared.
         * Sample example,
            a --> [5, 3, 7, 8, 5]
            for(int i=0; i<n; ++i) st.insert({a[i], i});
            
            auto it1=st.upper_bound({7, -1}); cout << ((*it1)[0]) << "\n"; // Output: 7
            auto it2=st.upper_bound({7, 6}); cout << ((*it2)[0]) << "\n"; // Output: 8
        */
        // auto it=st.upper_bound({t, mxN+1});
        auto it=st.lower_bound({t+1, -1});
        if(it==st.begin())
            cout << "-1\n";
        else {
            --it;
            cout << ((*it)[0]) << "\n";
            st.erase(it);
        }
    }
    
    return 0;
}
```
