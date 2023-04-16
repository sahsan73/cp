/*
APPROACH: BFS
*/
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode *> p, q;
        p.push(root);
        vector<pair<TreeNode*, TreeNode*>> vp;
        vector<int> sums;
        
        while(!p.empty()) {
            TreeNode *curr = p.front();
            p.pop();
            
            int x = 0;
            if(curr->left && curr->right) {
                x += curr->left->val + curr->right->val;
                vp.push_back({curr->left, curr->right});
                
                q.push(curr->left);
                q.push(curr->right);
            } else if(curr->left) {
                x += curr->left->val;
                vp.push_back({curr->left, nullptr});
                
                q.push(curr->left);
            } else if(curr->right) {
                x += curr->right->val;
                vp.push_back({nullptr, curr->right});
                
                q.push(curr->right);
            } else {
                vp.push_back({nullptr, nullptr});
            }
            sums.push_back(x);
            
            if(p.empty()) {
                int ts = accumulate(sums.begin(), sums.end(), 0);
                for(int i=0; i<sums.size(); ++i) {
                    if(vp[i].first) {
                        (vp[i].first)->val = ts - sums[i];
                    }
                    if(vp[i].second) {
                        (vp[i].second)->val = ts - sums[i];
                    }
                }
                
                p.swap(q);
                vp.clear();
                sums.clear();
            }
        }
        
        return root;
    }
};

// P.S.: Will think for optimization
