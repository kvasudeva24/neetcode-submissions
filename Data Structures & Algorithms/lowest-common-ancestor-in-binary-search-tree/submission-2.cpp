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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int first = p->val;
        int second = q->val;
        if(first > second) swap(first, second);
        return dfs(root, first, second);
    }
    TreeNode* dfs(TreeNode* root, const int& p, const int& q){
        if(p == root->val || q == root->val) return root;

        //in two diff subtrees
        if(root->val > p && root->val < q) return root;
        else if(root->val > p && root->val > q) return dfs(root->left, p, q);
        else return dfs(root->right, p, q);

    }
};
