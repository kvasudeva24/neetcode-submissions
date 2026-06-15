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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int p_val = p->val;
        int q_val = q->val;

        if ( p_val > q_val) {
            std::swap(p_val, q_val);
        }
        
        return LCA(root, p_val, q_val);
    }

    TreeNode* LCA(TreeNode* v, const int& p, const int& q) {
        if ( p <= v->val && v->val <= q ) {
            return v;
        } else if ( v->val < p ) {
            return LCA(v->right, p, q);
        } else {
            return LCA(v->left, p, q);
        }
    }


};
