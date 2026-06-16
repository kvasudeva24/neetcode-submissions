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
    int maxPathSum(TreeNode* root) {
        if ( !root ) { return 0; }

        int res = root->val;
        maxPath(root, res);
        return res;
    }

    int maxPath(TreeNode* v, int& curMax) {
        if ( !v ) return 0;

        int left = maxPath(v->left, curMax);
        int right = maxPath(v->right, curMax);

        int split = left + right + v->val;

        curMax = max(curMax, split);

        return max(0, max(left, right) + v->val);
    }
};
