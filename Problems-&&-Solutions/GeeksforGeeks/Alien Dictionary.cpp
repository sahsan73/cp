/*
Problem Statement: https://practice.geeksforgeeks.org/problems/alien-dictionary/1
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
APPROACH: TOPO SORT
    - Kahn's Algorithm
*/
class Solution{
public:
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int> adj[k], indeg(k, 0), st;
        for(int i=1; i<n; ++i) {
            string s1 = dict[i-1], s2 = dict[i];
            for(int j=0; j<min(s1.size(), s2.size()); ++j) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    ++indeg[s2[j]-'a'];
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i=0; i<k; ++i) {
            if(indeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v: adj[u]) {
                --indeg[v];
                if(indeg[v] == 0)
                    q.push(v);
            }
            st.push_back(u);
        }
        string answer;
        for(int x: st)
            answer.push_back(x+'a');
        return answer;
    }
};
