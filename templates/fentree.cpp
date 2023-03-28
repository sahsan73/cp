const int mxN=1e5;  // maximum size of the input array can have
int n;  // actual size of the input array

struct FenTree {
	ll a[mxN+1];
	
	void upd(int i, ll x) {
		for(++i; i<=n; i+=i&-i)
			a[i]+=x;
	}

	ll qry(int i) {
		ll res=0;
		for(; i>0; i-=i&-i)
			res+=a[i];
		return res;
	}
} ft;
