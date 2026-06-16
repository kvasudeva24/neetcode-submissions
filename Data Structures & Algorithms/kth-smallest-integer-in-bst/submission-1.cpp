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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        inOrder(root, order);
        return order[k-1];
    }

    void inOrder(TreeNode* v, vector<int>& order) {
        if ( !v ) return;

        inOrder(v->left, order);
        order.push_back(v->val);
        inOrder(v->right, order);


    }
};
