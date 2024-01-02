using ll = long long;
const int sz = 30;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost) {
        vector<vector<ll>> dp(sz, vector<ll>(sz, 1e18));
        for(int i = 0; i < sz; ++i)
            dp[i][i] = 0ll;
        for(int i = 0; i < (int)original.size(); ++i)
            dp[original[i]-'a'][changed[i]-'a'] = min(dp[original[i]-'a'][changed[i]-'a'], cost[i] + 0ll);
        
        for(int k = 0; k < sz; ++k) {
            for(int i = 0; i < sz; ++i) {
                for(int j = 0; j < sz; ++j) {
                    if(dp[i][k]==1e18 || dp[k][j]==1e18)
                        continue;
                    dp[i][j]=min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        ll answer = 0;
        for(int i = 0; i < (int)source.size(); ++i) {
            ll x = dp[source[i]-'a'][target[i]-'a'];
            if(x == 1e18)
                return -1;
            answer += x;
        }
        return answer;
    }
};
