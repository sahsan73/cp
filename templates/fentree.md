```cpp
const int mxN=1e5;
int n;

struct FenTree {
    ll a[mxN+1];
    
    void upd(int i, ll x) {
        for(++i; i<=n; i+=i&-i)
            a[i]+=x;
    }
    
    ll qry(int i) {
        ll res=0;
        for(++i; i; i-=i&-i)
            res+=a[i];
        return res;
    }
} ft;
```
