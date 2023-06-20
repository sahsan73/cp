using ll=long long;

const int mxN=1e5;  // maximum size of input array can have
int n;  // actual size of input array

struct SegTree {
	ll a[4*mxN];
	void bld(int i, int s, int e, vector<ll> &arr) {
		if(s==e) {
			a[i]=arr[s];
			return;
		}

		int m=(s+e)/2;
		bld(2*i+1, s, m, arr);	// build left subtree
		bld(2*i+2, m+1, e, arr);  // build right subtree

		a[i]=a[2*i+1]+a[2*i+2];	// update current node
	}
	void bld(vector<ll> &arr) {return bld(0, 0, n-1, arr);}
	
	ll qry(int i, int s, int e, int l, int r) {
		if(s>r||e<l) return 0;	// no-overlap
		if(s>=l&&e<=r) return a[i];	// complete overlap

		// partial overlap
		int m=(s+e)/2;
		ll ls=qry(2*i+1, s, m, l, r);	// left sum
		ll rs=qry(2*i+2, m+1, e, l, r);	  // right sum
		return ls+rs;
	}
	ll qry(int l, int r) {return qry(0, 0, n-1, l, r);}

	void upd(int i, int s, int e, int idx, int val) {
		if(s==e) {
			a[i]=val;
			return;
		}

		int m=(s+e)/2;
		if(idx<=m) { // idx lies on the left subtree
			upd(2*i+1, s, m, idx, val);
		} else {  // idx lies on the right substree
			upd(2*i+2, m+1, e, idx, val);
		}

		// update the current node
		a[i]=a[2*i+1]+a[2*i+2];
	}
	void upd(int idx, int val) {return upd(0, 0, n-1, idx, val);}
} st;
