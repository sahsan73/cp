// VERDICT: AC
using ll = long long;

class Solution {
public:
    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost) {
        int id = 0;
        unordered_map<string, int> mp;
        vector<vector<ll>> dp(212, vector<ll>(212, 1e18));
        for(int i = 0; i < 212; ++i)
            dp[i][i] = 0ll;
        for(int i = 0; i < (int)original.size(); ++i) {
            if(!mp.count(original[i]))
                mp[original[i]] = id++;
            if(!mp.count(changed[i]))
                mp[changed[i]] = id++;
            
            int u = mp[original[i]], v = mp[changed[i]];
            dp[u][v] = min(dp[u][v], cost[i] + 0ll);
        }
        
        int sz = id + 5;
        for(int k = 0; k < sz; ++k) {
            for(int i = 0; i < sz; ++i) {
                if(dp[i][k] == 1e18)
                    continue;
                
                for(int j = 0; j < sz; ++j) {
                    if(dp[k][j]==1e18)
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        int n = (int)source.size();
        unordered_set<int> st;
        for(string s: original)
            st.insert(s.size());
        vector<ll> dp2(n+1, 1e18);
        dp2[0] = 0ll;
        for(int i = 1; i <= n; ++i) {
            if(source[i-1] == target[i-1])
                dp2[i] = min(dp2[i], dp2[i-1]);
            
            for(int j: st) {
                if(i-j < 0)
                    continue;
                string s = source.substr(i-j, j);
                string t = target.substr(i-j, j);
                
                if(s == t && dp2[i-j]<1e18)
                    dp2[j] = min(dp2[j], dp2[i-j]);
                else if(mp.count(s) && mp.count(t) && dp2[i-j]<1e18 && dp[mp[s]][mp[t]]<1e18)
                    dp2[i] = min(dp2[i], dp2[i-j] + dp[mp[s]][mp[t]]);
                
            }
        }
        
        if(dp2[n] == 1e18)
            return -1;
        return dp2[n];
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// VERDICT: TLE
using ll = long long;

class Solution {
public:
    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost) {
        int id = 0;
        unordered_map<string, int> mp;
        vector<vector<ll>> dp(212, vector<ll>(212, 1e18));
        for(int i = 0; i < 212; ++i)
            dp[i][i] = 0ll;
        for(int i = 0; i < (int)original.size(); ++i) {
            if(!mp.count(original[i]))
                mp[original[i]] = id++;
            if(!mp.count(changed[i]))
                mp[changed[i]] = id++;
            
            int u = mp[original[i]], v = mp[changed[i]];
            dp[u][v] = min(dp[u][v], cost[i] + 0ll);
        }
        
        int sz = id + 5;
        for(int k = 0; k < sz; ++k) {
            for(int i = 0; i < sz; ++i) {
                if(dp[i][k] == 1e18)
                    continue;
                
                for(int j = 0; j < sz; ++j) {
                    if(dp[k][j]==1e18)
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        int n = (int)source.size();
        vector<ll> dp2(n+1, 1e18);
        dp2[0] = 0ll;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                string s = source.substr(j-1, i-j+1);
                string t = target.substr(j-1, i-j+1);
                
                if(s == t && dp2[j-1]<1e18)
                    dp2[j] = min(dp2[j], dp2[j-1]);
                else if(mp.count(s) && mp.count(t) && dp2[j-1]<1e18 && dp[mp[s]][mp[t]]<1e18)
                    dp2[i] = min(dp2[i], dp2[j-1] + dp[mp[s]][mp[t]]);
                
            }
        }
        
        if(dp2[n] == 1e18)
            return -1;
        return dp2[n];
    }
};
