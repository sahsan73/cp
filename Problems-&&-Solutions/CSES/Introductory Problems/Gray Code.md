# Gray Code
Click [here](https://cses.fi/problemset/task/2205) to see the problem statement.   

### APPROACH - I
![explanation-image](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/introductory-problems-gray-code-part-1.png)   

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> gc(int n) {
    if(n==0)
        return {0};
    
    vector<int> gn_1=gc(n-1);
    vector<int> res=gn_1;
    for(int i=gn_1.size()-1; ~i; --i) {
        bitset<32> bs(gn_1[i]);
        bs.flip(n-1); // flips (n-1)th bit, 0-based indexing
        res.push_back(bs.to_ulong());
    }
    return res;
}

int main() {
    cin >> n;
    
    vector<int> ans=gc(n);
    for(int i=0; i<ans.size(); ++i) {
        bitset<32> bs(ans[i]);
        cout << bs.to_string().substr(32-n) << "\n";
    }
    
    return 0;
}
```


### APPROACH - II
![explanation-image](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/introductory-problems-gray-code-part-2.png)   

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

void gc(bitset<32> &bs, int n) {
    if(n==0) {
        ans.push_back(bs.to_ulong());
        return;
    }
    
    gc(bs, n-1);
    bs.flip(n-1); // flips (n-1)th bit, 0-based indexing
    gc(bs, n-1);
}

int main() {
    cin >> n;
    
    bitset<32> bs(0);
    gc(bs, n);
    for(int i=0; i<ans.size(); ++i) {
        bitset<32> bs(ans[i]);
        cout << bs.to_string().substr(32-n) << "\n";
    }
    
    return 0;
}
```


### APPROACH - III
Resources: [cp-algorithms](https://cp-algorithms.com/algebra/gray-code.html)   
&nbsp;
![explanation-image](https://github.com/sahsan73/cp/blob/main/Problems-%26%26-Solutions/CSES/assets/images/introductory-problems-gray-code-part-3.png)   

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

void gc(int n) {
    for(int i=0; i<(1<<n); ++i) {
        int c=i^(i>>1);
        ans.push_back(c);
    }
}

int main() {
    cin >> n;
    
    gc(n);
    for(int i=0; i<ans.size(); ++i) {
        bitset<32> bs(ans[i]);
        cout << bs.to_string().substr(32-n) << "\n";
    }
    
    return 0;
}
```
