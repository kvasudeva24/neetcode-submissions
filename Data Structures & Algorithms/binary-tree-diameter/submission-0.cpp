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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = -1;
        maxDiameter(root, result);
        return result;
    }

    int maxDiameter(TreeNode* v, int& cur_max) {
        if ( !v ) return -1;

        int left = maxDiameter(v->left, cur_max);
        int right = maxDiameter(v->right, cur_max);

        int subtree_height = 2 + left + right;
        cur_max = max(subtree_height, cur_max);

        return 1 + max(left, right);
    }
};
