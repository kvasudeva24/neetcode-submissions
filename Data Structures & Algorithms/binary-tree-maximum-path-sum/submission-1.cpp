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
        int ans = root->val;
        int dummy = dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* node, int& ans){
        if(!node) return 0;

        int left = dfs(node->left, ans);
        int right = dfs(node->right, ans);

        left = max(left, 0);
        right = max(right, 0);

        int split = node->val + left + right;
        ans = max(ans, split);

        return node->val + max(left, right);
    }
};
