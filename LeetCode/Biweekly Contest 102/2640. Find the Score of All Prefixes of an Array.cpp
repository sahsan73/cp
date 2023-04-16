/*
APPROACH: PREFIX SUM

COMPLEXITY:
    - TC = O(n)
    - SC = O(n) // for storing results
*/
using ll = long long;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<ll> ans;
        ll mx=-1, x=0;
        for(int i=0; i<nums.size(); ++i) {
            mx = max(mx, (ll)nums[i]);
            x += mx + (ll)nums[i];
            
            ans.push_back(x);
        }
        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH:
    - Using Fenwick Tree
    - DURING CONTEST

COMPLEXITY:
    - TC = O(nlogn)
    - SC = O(n)

VERDICT: AC
*/
using ll=long long;
const int mxN = 1e5;
int n;

struct FenTree {
    int a[mxN+1];
    
    void upd(int i, int x) {
        for(++i; i<=n; i+=i&-i)
            a[i] = max(a[i], x);
    }
    
    int qry(int i) {
        int ans = -1e9-5;
        for(++i; i>0; i-=i&-i) {
            ans = max(ans, a[i]);
        }
        return ans;
    }
} ft;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        memset(ft.a, 0, 4*(mxN+1));
        n = (int)nums.size();
        for(int i=0; i<n; ++i) ft.upd(i, nums[i]);
        
        vector<ll> ans;
        ll x = 0;
        for(int i=0; i<n; ++i) {
            x += (ll)nums[i] + (ll)ft.qry(i);
            ans.push_back(x);
        }
        return ans;
    }
};
