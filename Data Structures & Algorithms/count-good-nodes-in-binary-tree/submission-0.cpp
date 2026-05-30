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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, root->val);
        return ans;
    }

    void dfs(TreeNode* root, int& ans, int cur_max){
        if(!root) return;

        if(root->val >= cur_max) ans++;

        dfs(root->left, ans, max(cur_max, root->val));
        dfs(root->right, ans, max(cur_max, root->val));
    }
};
