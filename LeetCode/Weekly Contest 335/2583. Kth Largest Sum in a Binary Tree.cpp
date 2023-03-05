/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef long long ll;
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode *> q1, q2;
        q1.push(root);
        
        priority_queue<ll> pq;
        ll ls = 0;
        while(q1.size()) {
            TreeNode *tmp = q1.front();
            q1.pop();
            ls += (ll)tmp->val;
            
            if(tmp->left) q2.push(tmp->left);
            if(tmp->right) q2.push(tmp->right);
            
            if(q1.empty()) {
                pq.push(ls);
                ls = 0;
                q2.swap(q1);
            }
        }
        
        if(k>pq.size()) return -1;
        while(--k) pq.pop();
        return pq.top();
    }
};
