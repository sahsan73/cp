class Solution {
public:
    int minAbsoluteDifference(vector<int> &nums, int x) {
        set<int> st;
        int n = (int)nums.size(), answer = 1e9+5;
        for(int i=0; i<n; ++i) {
            if(i >= x)
                st.insert(nums[i-x]);
            
            // Case-I: find y >= nums[i]
            auto it = st.lower_bound(nums[i]);
            if(it != st.end())
                answer = min(answer, *it - nums[i]);
            
            // Case-II: find y < nums[i], y should be maximum of
            // all numbers which are less than nums[i]
            if(it != st.begin())
                answer = min(answer, nums[i] - *(--it));
        }
        return answer;
    }
};
