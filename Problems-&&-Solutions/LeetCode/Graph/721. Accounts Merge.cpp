/*
Problem Statement: 
*/
struct DisjointSetUnion {
    int p[1000], s[1000];
    DisjointSetUnion(int n) {
        iota(p, p+n, 0);
        fill(s, s+n, 1);
    }

    int find(int u) {
        return u^p[u] ? p[u] = find(p[u]) : u;
    }

    void join(int u, int v) {
        if((u=find(u)) == (v=find(v)))
            return;
        
        if(s[u] < s[v])
            swap(u, v);
        p[v] = u;
        s[u] += s[v];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // each account represents a node (i.e., accounts[i] <-- node)
        // now let's assign each mail with the node
        int n = (int)accounts.size();
        unordered_map<string, int> mp;
        DisjointSetUnion dsu(n);
        for(int i=0; i<n; ++i) {
            for(int j=1; j<accounts[i].size(); ++j) {
                string s = accounts[i][j];
                // if a node id is already assigned to a mail, means the accounts ith and already
                // assigned value belong to the same person
                if(mp.count(s)) {
                    dsu.join(i, mp[s]);
                } else {
                    mp[s] = i;
                }
            }
        }

        // let's merge the mails for same accounts
        unordered_map<int, set<string>> mp2;
        for(auto &p: mp) {
            int i = dsu.find(p.second);
            mp2[i].insert(p.first);
        }

        // final list of accounts
        vector<vector<string>> answer;
        for(auto &p: mp2) {
            string s = accounts[p.first][0];
            answer.push_back({s});
            for(auto &s2: p.second)
                answer.back().push_back(s2);
        }
        return answer;
    }
};
