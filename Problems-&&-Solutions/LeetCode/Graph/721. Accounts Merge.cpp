/*
Problem Statement: https://leetcode.com/problems/accounts-merge/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DSU
*/
class Solution {
private:
    int p[1000], s[1000];

    int find(int u) {
        return u^p[u] ? p[u]=find(p[u]) : u;
    }

    void join(int u, int v) {
        if((u=find(u)) == (v=find(v)))
            return;
        if(s[u] < s[v]) swap(u, v);
        p[v] = u;
        s[u] += s[v];
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = (int)accounts.size();
        iota(p, p+n, 0);
        fill(s, s+n, 1);

        // each account represents a node (i.e., accounts[i] --> a node with id i)
        // now, let's assign each email with its node id
        unordered_map<string, int> mp;
        for(int i=0; i<n; ++i) {
            for(int j=1; j<accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if(!mp.count(email)) {
                    mp[email] = i;
                } else {
                    // if an email already assigned to a node id, this means curr ith account (node i)
                    // and already assigned account (id --> mp[email]) belong to the same user.
                    join(mp[email], i);
                }
            }
        }

        unordered_map<int, set<string>> mp2;
        for(auto &[email, i]: mp) {
            int id = find(i);
            mp2[id].insert(email);
        }
        
        vector<vector<string>> answer;
        for(auto &[id, st]: mp2) {
            vector<string> finalAccount(st.begin(), st.end());
            finalAccount.insert(finalAccount.begin(), accounts[id][0]);
            answer.push_back(finalAccount);
        }
        return answer;
    }
};
