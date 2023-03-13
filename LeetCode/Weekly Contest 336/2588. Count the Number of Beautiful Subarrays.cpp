/*
SAME CONCEPT AS: "560. Subarray Sum Equals K"
    My Sol: https://github.com/sahsan73/problems-solutions/blob/main/LeetCode/560.%20Subarray%20Sum%20Equals%20K.cpp


FOR ANY TWO NUMBERS IN A SUBARRAY:
    - X and Y, remove 2^k from both of them, where k is the kth set bit of X and Y
      is equivalent to [X(xor)Y]
*/

typedef long long ll;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, ll> seen;
        seen[0] = 1;

        ll cnt=0, px=0; // px ==> prefix xor
        for(int i=0; i<nums.size(); ++i) {
            px ^= nums[i];
            cnt += seen[px];

            ++seen[px];
        }
        return cnt;
    }
};
