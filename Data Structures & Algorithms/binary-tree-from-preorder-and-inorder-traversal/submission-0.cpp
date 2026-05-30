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
    int preIdx = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for(int i = 0; i<inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1, map);
    }
    TreeNode* dfs(const vector<int>& preorder, int left,  int right, unordered_map<int,  int>& indices){
        if (left > right) return nullptr;

        int val = preorder[preIdx++];
        int inord_idx = indices[val];
        TreeNode* root = new TreeNode(val);

        root->left = dfs(preorder, left, inord_idx - 1, indices);
        root->right = dfs(preorder, inord_idx + 1, right, indices);

        return root;

    }
};
