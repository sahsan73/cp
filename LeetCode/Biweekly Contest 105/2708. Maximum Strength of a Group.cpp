typedef long long ll;

class Solution {
private:
    int n;
    ll ans;
    
    void dfs(int i, vector<int> &nums, ll x) {
        if(i >= n) {
            ans = max(ans, x);
            return;
        }
        
        dfs(i+1, nums, (ll)nums[i]*x);
        dfs(i+1, nums, x);
    }
    
public:
    long long maxStrength(vector<int> &nums) {
        n = (int)nums.size();
        if(n == 1) return nums[0];
        ans = LLONG_MIN;
        
        ll c1=0, c2=0, c3=0;
        for(int i=0; i<n; ++i) {
            if(nums[i] < 0) ++c1;
            else if(nums[i] == 0) ++c2;
            else ++c3;
        }
        
        if(c3>0 || c1>1) dfs(0, nums, 1);
        else dfs(0, nums, 0);
        return ans;
    }
};
