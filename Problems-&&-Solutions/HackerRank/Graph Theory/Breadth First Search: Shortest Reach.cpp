/*
Problem Statement: https://www.hackerrank.com/challenges/bfsshortreach/problem?isFullScreen=true
*/

vector<int> bfs(int n, int m, vector<vector<int>> e, int s) {
    vector<int> adj[n];
    for(int i=0; i<m; ++i) {
        adj[e[i][0]-1].push_back(e[i][1]-1);
        adj[e[i][1]-1].push_back(e[i][0]-1);
    }
    
    vector<int> d(n, 1e9);
    queue<array<int, 2>> qu;
    --s;
    qu.push({s, 0}); // {node, distance}
    d[s] = 0;
    while(!qu.empty()) {
        auto u = qu.front();
        qu.pop();
        for(int v: adj[u[0]]) {
            if(d[v] == 1e9) {
                d[v] = u[1] + 1;
                qu.push({v, d[v]});
            }
        }
    }
    
    vector<int> answer;
    for(int i=0; i<n; ++i) {
        if(i == s) continue;
        
        if(d[i] == 1e9) {
            answer.push_back(-1);
        } else {
            answer.push_back(6*d[i]);
        }
    }
    return answer;
}
