/*
APPROACH: GREEDY
    - Calculate total number of NON-OVERLAPPING ranges, say N
    - Then, total number of ways of grouping = 2^N

COMPLEXITY:
    - TC = O(n)
    - SC = O(1)
*/

typedef long long ll;
const ll mod = 1e9 + 7;

class Solution {
private:
    // pow(a, b) % mod
    int bin_pow(ll a, ll b) {
        ll res = 1;
        while(b > 0) {
            if(b&1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int n = (int)ranges.size();
        
        ll N = 1;  // number of non-overlapping ranges
        int l = ranges[0][0], h = ranges[0][1];     // l ==> low,      h == > high
        for(int i=1; i<n; ++i) {
            if(ranges[i][0] <= h) {
                h = max(h, ranges[i][1]);
            } else {
                ++N;
                l = ranges[i][0], h = ranges[i][1];
            }
        }
        // cout << "(" << n << ", " << N << ")" << endl;
        
        return bin_pow(2, N);
    }
};
