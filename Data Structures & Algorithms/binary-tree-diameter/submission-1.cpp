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
        int diam = 0;
        Depth(root, diam);
        return diam;
    }

    int Depth(TreeNode* v, int& diam) {
        if (!v) {return 0;}

        int l = Depth(v->left, diam);
        int r = Depth(v->right, diam);

        diam = std::max(diam, l+r);

        return (max(l, r) + 1);

    }
};
