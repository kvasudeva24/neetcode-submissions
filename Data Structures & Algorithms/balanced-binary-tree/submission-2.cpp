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
    bool isBalanced(TreeNode* root) {
        bool state = true;
        heightHelper(root, state);
        return state;
    }

    int heightHelper(TreeNode* v, bool& invariant) {
        if (!v) { return 0; }

        int l = heightHelper(v->left, invariant);
        int r = heightHelper(v->right, invariant);

        if (invariant == false){
            return 0;
        }

        if ( abs(l-r) > 1 ) {
            invariant = false;
        }

        return (max(l, r) + 1);
    }
};
