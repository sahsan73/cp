/*
APPROACH: RECURSION

VERDIC: AC
*/
class Solution {
private:
    bool dfs(int currIdx, string &s, int target) {
        if(currIdx >= s.size()) return target==0;
        if(target < 0) return 0;

        for(int len=1; len<=s.size()-currIdx; ++len) {
            int val = stoi(s.substr(currIdx, len));
            if(dfs(currIdx+len, s, target-val)) return 1;
        }
        return 0;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; ++i) {
            int x = i*i;
            string s = to_string(x);
            if(dfs(0, s, i)) ans += x;
        }
        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Top-Down(Recursion + Memoization)

VERDICT: TLE
*/
class Solution {
private:
    int target;
    
    bool dfs(int curr, string &s, int sum, vector<vector<int>> &dp) {
        if(curr >= s.size()) return sum==target;
        if(dp[curr][sum] != -1) return dp[curr][sum];
        
        bool res = 0;
        for(int len=1; len<=s.size()-curr; ++len) {
            int val = stoi(s.substr(curr, len));
            sum += val;
            if(sum > target) break;
            
            res |= dfs(curr+len, s, sum, dp);
            if(res) break;
            sum -= val;
        }
        return dp[curr][sum] = res;
    }
    
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; ++i) {
            target = i;
            string s = to_string(i*i);
            vector<vector<int>> dp(s.size(), vector<int>(10001, -1));
            
            if(dfs(0, s, 0, dp)) ans += i*i;
        }
        return ans;
    }
};
