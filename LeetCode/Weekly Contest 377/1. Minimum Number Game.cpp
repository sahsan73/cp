class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> answer;
        int n = (int)nums.size();
        for(int i=1; i<n; i+=2) {
            answer.push_back(nums[i]);
            answer.push_back(nums[i-1]);
        }
        return answer;
    }
};
