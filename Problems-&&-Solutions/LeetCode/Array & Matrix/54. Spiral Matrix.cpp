/*
Problem Statement: https://leetcode.com/problems/spiral-matrix/description/
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: DFS
*/
class Solution {
private:
    const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
    int m, n;
    vector<int> answer;

    void dfs(int i, int j, vector<vector<int>> &matrix, int k) {
        if(answer.size() == m*n)
            return;
        
        auto e = [&](int r, int c) {
            return (r>=0 && r<m && c>=0 && c<n && matrix[r][c]!=1e9);
        };

        answer.push_back(matrix[i][j]);
        matrix[i][j] = 1e9;
        if(e(i+d4i[k], j+d4j[k]))
            dfs(i+d4i[k], j+d4j[k], matrix, k);
        else {
            k = (k + 1) % 4;
            dfs(i+d4i[k], j+d4j[k], matrix, k);
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        m = (int)matrix.size();
        n = (int)matrix[0].size();
        
        answer.clear();
        dfs(0, 0, matrix, 1);
        return answer;
    }
};
