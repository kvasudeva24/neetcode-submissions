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
    bool isValidBST(TreeNode* root) {

        return ValidBST(root, INT_MIN, INT_MAX);

    }

    bool ValidBST(TreeNode* v, int low, int hi) {
        if ( !v ) { return true; }

        auto left = ValidBST(v->left, low, v->val);
        auto right = ValidBST(v->right, v->val, hi);

        return ( (low < v->val) && (v->val < hi) && left && right);
        
        
    }

};
