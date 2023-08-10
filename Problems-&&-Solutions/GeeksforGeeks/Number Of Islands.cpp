/*
Problem Statement: https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DISJOINT SET UNION (DSU)
*/
struct DisjointSetUnion {
    int p[10000], s[10000];
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
private:
    bool mat[100][100];
    const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
    
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        memset(mat, 0, sizeof(mat));
        
        auto inbound = [&](int r, int c) {
            return (r>=0 && r<n && c>=0 && c<m);
        };
        
        DisjointSetUnion dsu(n*m);
        vector<int> answer;
        int cnt = 0;
        for(auto &op: operators) {
            int r = op[0], c = op[1];
            if(mat[r][c] == 1) {
                answer.push_back(cnt);
                continue;
            }
            
            mat[r][c] = 1;
            ++cnt;
            
            for(int k=0; k<4; ++k) {
                int nr = r + d4i[k];
                int nc = c + d4j[k];
                if(inbound(nr, nc) && mat[nr][nc]) {
                    int u = r * m + c;
                    int v = nr * m + nc;
                    if(dsu.find(u) != dsu.find(v)) {
                        --cnt;
                        dsu.join(u, v);
                    }
                }
            }
            answer.push_back(cnt);
        }
        return answer;
    }
};
