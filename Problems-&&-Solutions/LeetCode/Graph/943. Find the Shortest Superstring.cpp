


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: Travelling Salesman Problem (TSP)

Cost of moving from node u to node v => NON-OVERLAPPING substring of v
    - for example, if s1 = "abcde" and s2 = "defg"
      then adj[u][v] = "fg"; where u and v are the indices(node ID) of s1 and s2 respectively
      in the list of words

    - NON-OVERLAPPING substring must be minimum.

VERDICT: TLE
*/
#define vt vector
#define sz(x) (int)(x).size()

class Solution {
private:
    int n;

    void bldAdjMat(vt<string> &words, vt<vt<string>> &adj) {
        for(int u=0; u<n; ++u) {
            string s1 = words[u];
            for(int v=0; v<n; ++v) {
                if(u == v) continue;

                string s2=words[v];
                // For s1, [k1....n-k1] substring, k1-->index, n-k1-->length
                // For s2, [0.....k2] substring, 0-->index, k2-->length
                string nonOverlappingS2=s2;
                for(int k1=0; k1<sz(s1); ++k1) {
                    for(int k2=1; k2<=sz(s2); ++k2) {
                        if(s2.substr(0, k2) == s1.substr(k1)) {
                            // found the MAXIMUM overlapping substring, now 
                            // let's find out the MINIMUM non-overlapping substring
                            nonOverlappingS2 = s2.substr(k2);
                            goto x;
                        }
                    }
                }

                x:;
                adj[u][v] = nonOverlappingS2;
            }
        }
    }

    string tsp(int u, int vis, vt<vt<string>> &adj, vt<vt<string>> &dp) {
        if(vis == (1<<n)-1) {
            return "";
        }
        if(!dp[vis][u].empty()) {
            return dp[vis][u];
        }

        string res;
        for(int v=0; v<n; ++v) {
            if((vis&(1<<v)) == 0) {
                string tmp = adj[u][v] + tsp(v, vis|(1<<v), adj, dp);
                if(res.empty() || (!res.empty() && sz(res)>sz(tmp))) {
                    res = tmp;
                }
            }
        }
        return dp[vis][u] = res;
    }

public:
    string shortestSuperstring(vector<string> &words) {
        // build adjacency matrix
        n = (int)words.size();
        vt<vt<string>> adj(n, vector<string>(n));
        bldAdjMat(words, adj);

        // for(int i=0; i<n; ++i) {
        //     for(int j=0; j<n; ++j) {
        //         cout << adj[i][j] << "\t";
        //     }
        //     cout << "\n";
        // }

        string answer;
        for(int u=0; u<n; ++u) {
            int vis = 0;
            vt<vt<string>> dp(1<<n, vt<string>(n));
            string tmp = words[u] + tsp(u, vis, adj, dp);
            if(answer.empty() || (!answer.empty() && sz(answer)>sz(tmp))) {
                answer = tmp;
            }
        }
        return answer;
    }
};
