using ll=long long;
const int mxN=1e5; // max input size
int n, arr[mxN];

struct SegTree {
	int a[mxN]; // 1-indexed based underlying array
	void bld(int i, int s, int e) {
		if(s==e) {
			a[i]=arr[s];
			return;
		}

		int m=(s+e)/2;
		bld(2*i, s, m);
		bld(2*i+1, m+1, e);
		a[i]=a[2*i]+a[2*i+1];
	}
	void bld() {return bld(1, 0, n-1);}

	int qry(int i, int s, int e, int l, int r) {
		if(s>r||e<l) return 0; // no overlap
		if(s>=l&&e<=r) return a[i]; // complete overlap

		//partial overlap
		int m=(s+e)/2;
		int ls=qry(2*i, s, m, l, r); // left sum
		int rs=qry(2*i+1, m+1, e, l, r); // right sum
		return ls+rs;
	}
	int qry(int l, int r) {return qry(1, 0, n-1, l, r);}

	void upd(int i, int s, int e, int idx, int val) {
		if(s==e) {
			a[i]=val;
			return;
		}

		int m=(s+e)/2;
		if(idx<=m) { // idx lies on left subtree
			upd(2*i, s, m, idx, val);
		} else { // idx lies on right subtree
			upd(2*i+1, m+1, e, idx, val);
		}

		// update the current, since child node has changed
		a[i]=a[2*i]+a[2*i+1];
	}
	void upd(int idx, int val) {return upd(1, 0, n-1, idx, val);}
} st;
