class Solution {
public:
    bool hasTrailingZeros(vector<int> &nums) {
        int cnt = 0;
        for(int x: nums)
            if(x%2 == 0)
                ++cnt;
        return cnt > 1;
    }
};
