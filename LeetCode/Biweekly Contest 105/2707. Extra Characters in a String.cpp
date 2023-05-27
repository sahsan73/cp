/*
APPROACH: DYNAMIC PROGRAMMING
    - Implementation: Bottom-Up(Iteration + Tabulation)

VERDICT: AC
*/
class Solution {
private:
    const int INF = 1e9 + 5;
    int n;
    
public:
    int minExtraChar(string s, vector<string> &dict) {
        n = (int)s.size();
        unordered_set<string> st(dict.begin(), dict.end());
        
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        for(int i=1; i<=n; ++i) {
            for(int j=0; j<i; ++j) {
                string t = s.substr(j, i-j);
                if(st.count(t))
                    dp[i] = min(dp[i], dp[j]);
            }
            
            // substrings starting with s[i-1] do not exist
            dp[i] = min(dp[i], 1+dp[i-1]);
        }
        
        return dp[n];
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: BACKTRACKING

VERDICT: WA (Partially Accepted)
*/
class Solution {
private:
    const int INF = 1e9 + 5;
    int n;
    unordered_set<string> st;
    
    int solve(int curr, string &s, vector<int> &dp) {
        if(curr >= n) return 0;
        if(dp[curr] != INF) return dp[curr];
        
        int cnt = INF;
        for(int len=1; len<=n-curr; ++len) {
            string t = s.substr(curr, len);
            if(st.count(t))
                cnt = min(cnt, solve(curr+len, s, dp));
        }
        
        if(cnt == INF) return dp[curr] = 1 + solve(curr+1, s, dp);
        return dp[curr] = cnt;
    }
    
public:
    int minExtraChar(string s, vector<string> &dict) {
        n = (int)s.size();
        st.clear();
        for(auto w: dict) st.insert(w);
        
        vector<int> dp(n, INF);
        return solve(0, s, dp);
    }
};
