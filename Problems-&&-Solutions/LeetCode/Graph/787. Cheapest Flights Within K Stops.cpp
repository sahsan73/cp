class Solution {
private:
    #define ar array
    const int mxN = 100;

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<ar<int, 2>> adj[mxN];
        for(auto &e: flights) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        vector<int> price(n, 1e9);
        price[src] = 0;

        queue<ar<int, 3>> q;
        q.push({0, src, 0}); // {cntStops, node, price}
        while(!q.empty()) {
            int cntStops = q.front()[0];
            int u = q.front()[1], tp = q.front()[2]; // tp --> total price from src to u
            q.pop();
            if(cntStops==k+1 && u!=dst) continue;

            for(auto &it: adj[u]) {
                int v = it[0], p = it[1]; // p --> price from u to v
                if(tp + p < price[v]) {
                    price[v] = tp + p;
                    q.push({cntStops+1, v, price[v]});
                }
            }
        }

        return price[dst]==1e9 ? -1 : price[dst];
    }
};
