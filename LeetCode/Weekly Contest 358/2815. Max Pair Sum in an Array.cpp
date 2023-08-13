class Solution {
private:
    int get(int n) {
        int x = 0;
        while(n > 0) {
            x = max(x, n%10);
            n /= 10;
        }
        return x;
    }
    
public:
    int maxSum(vector<int> &nums) {
        int n = (int)nums.size();
        int answer = -1;
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(get(nums[i]) == get(nums[j])) {
                    answer = max(answer, nums[i]+nums[j]);
                }
            }
        }
        return answer;
    }
};
