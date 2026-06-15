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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if ( !root && !subRoot ) { return true; }
        if ( !root || !subRoot ) { return false; }

        if ( root->val != subRoot->val ){
            return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        } else {
            return sameTree(root, subRoot) || (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        }
    }

    bool sameTree(TreeNode* p, TreeNode* q) {
        if ( !p && !q ) { return true; }
        if ( !p || !q ) { return false; }

        return ((p->val == q->val) && sameTree(p->left, q->left) && sameTree(p->right, q->right));
    }
};
