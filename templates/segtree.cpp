using ll=long long;
const int mxN=1e5; // max input size
int n, x[mxN];

struct SegTree {
	int a[mxN]; // 1-indexed based underlying array
	void bld(int i=1, int s=0, int e=n-1) {
		if(s==e) {
			a[i]=x[s];
			return;
		}

		int m=(s+e)/2;
		bld(2*i, s, m);
		bld(2*i+1, m+1, e);
		a[i]=a[2*i]+a[2*i+1];
	}

	int qry(int l, int r, int i=1, int s=0, int e=n-1) {
		if(s>r||e<l) return 0; // no overlap
		if(s>=l&&e<=r) return a[i]; // complete overlap

		//partial overlap
		int m=(s+e)/2;
		int ls=qry(l, r, 2*i, s, m); // left subtree sum
		int rs=qry(l, r, 2*i+1, m+1, e); // right subtree sum
		return ls+rs;
	}

	void upd(int idx, int x, int i=1, int s=0, int e=n-1) {
		if(s==e) {
			a[i]=x;
			return;
		}

		int m=(s+e)/2;
		if(idx<=m) { // idx lies on left subtree
			upd(idx, x, 2*i, s, m);
		} else { // idx lies on right subtree
			upd(idx, x, 2*i+1, m+1, e);
		}

		// update the current, since child node has changed
		a[i]=a[2*i]+a[2*i+1];
	}
} st;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// LAZY PROPAGATION ////////////////////////////////////////////////////////
const int mxN=2e5;
int n, q, arr[mxN];

struct SegTree {
	int a[4*mxN], lz[4*mxN];
	void bld(int i=1, int s=0, int e=n-1) {
		if(s==e) {
			a[i]=arr[s], lz[i]=0;
			return;
		}

		int m=(s+e)/2;
		bld(2*i, s, m);
		bld(2*i+1, m+1, e);
		a[i]=a[2*i]+a[2*i+1];
	}

	void app(int i, int x, int s, int e) {
		a[i]+=x*(e-s+1);
		lz[i]+=x;
	}

	void psh(int i, int s, int m, int e) {
		app(2*i, lz[i], s, m); // push current lazy value to its left subtree "2*i"
		app(2*i+1, lz[i], m+1, e); // push current lazy value to its right subtree "2*i+1"
		lz[i]=0; // clear the lazy value in current subtree "i"
	}

	int qry(int l, int r, int i=1, int s=0, int e=n-1) {
		if(s>r||e<l) return 0;
		if(s>=l&&e<=r)
			return a[i];
		
		int m=(s+e)/2;
		psh(i, s, m, e); // push lazy value to the children of subtree "i"
		
		int ls=qry(l, r, 2*i, s, m); // left subtree sum
		int rs=qry(l, r, 2*i+1, m+1, e); // right subtree sum
		return ls+rs;
	}

	void upd(int l, int r, int x, int i=1, int s=0, int e=n-1) {
		if(s>r||e<l) return;
		if(s>=l&&e<=r) {
			app(i, x, s, e); // apply the update on current subtree "i"
			return;
		}

		int m=(s+e)/2;
		psh(i, s, m, e); // push lazy value to the children of subtree "i"

		upd(l, r, x, 2*i, s, m);
		upd(l, r, x, 2*i+1, m+1, e);
		a[i]=a[2*i]+a[2*i+1];
	}
} st;

Credit: William Lin
