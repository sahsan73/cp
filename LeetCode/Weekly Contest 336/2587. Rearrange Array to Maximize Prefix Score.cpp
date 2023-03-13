typedef long long ll;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        ll cnt = 0, ps = 0;
        for(int i=0; i<nums.size(); ++i) {
            ps += (ll)nums[i];
            if(ps > 0) ++cnt;
        }
        return (int)cnt;
    }
};
