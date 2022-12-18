/*
Problem Statement (LeetCode - 79): Given an m x n grid of characters board and a string word, return true if word exists in the grid.

                        The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally 
                        or vertically neighboring. The same letter cell may not be used more than once.
                        
Example #01:
    board = [['A', 'B', 'C', 'E'],
             ['S', 'F', 'C', 'S'],
             ['A', 'D', 'E', 'E']
            ]
            
    word = "ABCCED"
    
    ans = true
    
    
Example #03:
    board = [['A', 'B', 'C', 'E'],
             ['S', 'F', 'C', 'S'],
             ['A', 'D', 'E', 'E']
            ]
            
    word = "ABCB"
    
    ans = false
    
    
DESIGN INTUITION:
    - Iterate through the mxn grid board
    - If board[i][j] == word[0], go all four directions from (i,j) search for the word
    
    
    - Time Complexity: O(m*n*4^(m*n))
*/
class Solution {
    int m, n;
    vector<vector<bool>> used;

    bool dfs(vector<vector<char>> &board, int r, int c, string word, int curr) {
        if(curr >= (int)word.size()) return true;
        if(r<0||c<0||r>=m||c>=n||board[r][c]!=word[curr]||used[r][c]) return false;    

        used[r][c] = 1;
        bool left = dfs(board, r, c-1, word, curr+1);
        bool right = dfs(board, r, c+1, word, curr+1);
        bool up = dfs(board, r-1, c, word, curr+1);
        bool down = dfs(board, r+1, c, word, curr+1);
        if(left||right||up||down) return true;

        used[r][c] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = (int)board.size();
        n = (int)board[0].size();
        used = vector<vector<bool>>(m, vector<bool>(n, 0));

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(word[0] != board[i][j]) continue;
                
                if(dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};








///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Problem Statement (LeetCode - 212) : Given an m x n board of characters and a list of strings words, return all words on the board.

                   Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally
                   or vertically neighboring. The same letter cell may not be used more than once in a word.


Example #01:
    board = [['o', 'a', 'a', 'n'],
             ['e', 't', 'a', 'e'],
             ['i', 'h', 'k', 'r'],
             ['i', 'f', 'l', 'v']
            ]
    
    words = ["oath", "pea", "eat", "rain"]
    
    ans = ["eath", "oath"]
    
Example #02:
    board = [[


TEST CASES NEEDS TO BE CONSIDERED PRECEEDING ALGORITHM DESIGN
Case #01: This particular test case describes why we need SET to store the results (words) in the first place!!
    board = [['o', 'a', 'b', 'n'],
             ['o', 't', 'a', 'e'],
             ['a', 'h', 'k', 'r'],
             ['a', 'f', 'l', 'v']
            ]
    
    words = ["oa", "oaa"]
    
    
    ans = ["oa", "oaa"]



DESIGN INTUITION:
Worst Brute Force:
    - Previously we desgined the algorithm for searching a single word.
    - We can loop through the words and search each word individually
    
    - Time Complexity = O(w*m*n*4^(m*n)) , where w = number of words


Trie Data Structure:
    - We can search all the words which start with board[r][c] at the same time
    
    - Time Complexity = O(m*n*4^(m*n))

/*
const int mxN = 26;

class Trie {
public:
    Trie *children[mxN];
    bool is_end;

    Trie() {
        for(int i=0; i<mxN; ++i) children[i] = nullptr;
        is_end = false;
    }

    void insert(string word) {
        Trie *curr = this;
        for(int i=0; i<word.size(); ++i) {
            int idx = word[i] - 'a';
            if(curr->children[idx]==nullptr) {
                curr->children[idx] = new Trie();
            }

            curr = curr->children[idx];
        }

        curr->is_end = true;
    }
};

class Solution {
    int m_board, n_board;
    vector<vector<bool>> used;

public:
    void dfs(vector<vector<char>> &board, int r, int c, Trie *curr, string &word, set<string> &res) {
        if(r<0||c<0||r>=m_board||c>=n_board||used[r][c]||(curr->children[board[r][c]-'a']==nullptr)) return;

        int idx = board[r][c] - 'a';
        curr = curr->children[idx];
        if(curr==nullptr) return;

        word.push_back(board[r][c]);
        if(curr->is_end) {
            res.insert(word);
        }

        used[r][c] = 1;
        dfs(board, r, c-1, curr, word, res);    // left
        dfs(board, r, c+1, curr, word, res);    // right
        dfs(board, r-1, c, curr, word, res);    // up
        dfs(board, r+1, c, curr, word, res);    // down

        word.pop_back();
        used[r][c] = 0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        for(auto word: words) {
            root->insert(word);
        }

        m_board = (int)board.size();
        n_board = (int)board[0].size();
        used = vector<vector<bool>>(m_board, vector<bool>(n_board, 0));

        set<string> res;
        for(int i=0; i<m_board; ++i) {
            for(int j=0; j<n_board; ++j) {
                int idx = board[i][j] - 'a';
                if(root->children[idx]==nullptr) continue;

                string word;
                dfs(board, i, j, root, word, res);
            }
        }

        vector<string> ans;
        for(const auto &word: res) ans.push_back(word);
        return ans;
    }
};
