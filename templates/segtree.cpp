using ll=long long;

const int mxN=1e5;  // maximum size of input array can have
int n;  // actual size of input array

struct SegTree {
	ll a[4*mxN];
	void bld(int s, int e, int i, vector<ll> &arr) {
		if(s==e) {
			a[i]=arr[s];
			return;
		}

		int m=(s+e)/2;
		bld(s, m, 2*i+1, arr);	// build left subtree
		bld(m+1, e, 2*i+2, arr);  // build right subtree

		a[i]=a[2*i+1]+a[2*i+2];	// current node
	}
	void bld(vector<ll> &arr) {return bld(0, n-1, 0, arr);}
	
	ll qry(int s, int e, int i, int l, int r) {
		if(s>r||e<l) return 0;	// no-overlap
		if(s>=l&&e<=r) return a[i];	// complete overlap

		// partial overlap
		int m=(s+e)/2;
		ll ls=qry(s, m, 2*i+1, l, r);	// left sum
		ll rs=qry(m+1, e, 2*i+2, l, r);	  // right sum
		return ls+rs;
	}
	ll qry(int l, int r) {return qry(0, n-1, 0, l, r);}

	void upd(int s, int e, int i, int idx, int val) {
		if(s==e) {
			a[i]=val;
			return;
		}

		int m=(s+e)/2;
		if(idx<=m) { // idx lies on the left subtree
			upd(s, m, 2*i+1, idx, val);
		} else {  // idx lies on the right substree
			upd(m+1, e, 2*i+2, idx, val);
		}

		// update the current node
		a[i]=a[2*i+1]+a[2*i+2];
	}
	void upd(int idx, int val) {return upd(0, n-1, 0, idx, val);}
} st;
