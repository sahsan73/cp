/*
Problem Statement: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/
*/

class Solution {
private:
    vector<int> topoSort(vector<unordered_set<int>> &adj, vector<int> &d) {
        queue<int> qu;
        for(int i = 0; i < d.size(); ++i) {
            if(d[i] == 0)
                qu.push(i);
        }

        vector<int> order;
        while(qu.size()) {
            int u = qu.front();
            qu.pop();
            order.push_back(u);
            for(int v: adj[u]) {
                --d[v];
                if(d[v] == 0)
                    qu.push(v);
            }
        }
        return order.size()^d.size() ? vector<int>() : order;
    }

public:
    vector<int> sortItems(int n, int m, vector<int> &gp, vector<vector<int>> &beforeItems) {
        // group the isolated items as it needed for to create
        // adjacency list for groups
        for(int i = 0; i<n; ++i) {
            if(gp[i] == -1)
                gp[i] = m++;
        }
        // adj1 --> adjacency list for groups, adj2 --> adjacency list for items
        vector<unordered_set<int>> adj1(m), adj2(n);
        vector<int> d1(m), d2(n);
        for(int v = 0; v < n; ++v) {
            for(int u: beforeItems[v]) {
                if(gp[u]^gp[v] && !adj1[gp[u]].count(gp[v])) {
                    adj1[gp[u]].insert(gp[v]);
                    ++d1[gp[v]];
                }

                adj2[u].insert(v);
                ++d2[v];
            }
        }

        vector<int> gpOrder = topoSort(adj1, d1);
        vector<int> itemOrder = topoSort(adj2, d2);
        if(gpOrder.empty() || itemOrder.empty()) return {};

        // our items have been sorted, now we need to group them in order
        // to get our final result.
        // sorted item, itemOrder --> [0, 5, 6, 7, 2, 3, 1, 4] for the first example test case
        // and gpOrder --> [0, 1, 2, 4, 3]
        // itemOrder with their gp -->[0(2), 5(1), 6(0), 7(4), 2(1), 3(0), 1(3), 4(0)]
        vector<vector<int>> gpToItem(m);
        for(int item: itemOrder) {
            gpToItem[gp[item]].push_back(item);
            // cout << item << " " << gp[item] << "\n";
        }
        vector<int> answer;
        for(int gpNum: gpOrder) {
            for(int item: gpToItem[gpNum])
                answer.push_back(item);
        }
        return answer;
    }
};
