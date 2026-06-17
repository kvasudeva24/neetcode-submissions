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
    unordered_map<int, int> in_map;
    vector<int> preorder;
    vector<int> inorder;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> temp;
        for ( int i = 0; i < inorder.size(); i++ ) {
            temp[inorder[i]] = i;
        }
        in_map = temp;
        this->preorder = preorder;
        this->inorder = inorder;

        return constructTree(0, inorder.size() - 1, 0);
        
    }

    TreeNode* constructTree(int l, int r, int p) {
        if ( !(l <= r) ) { return nullptr; }

        int val = preorder[p];
        int idx = in_map[val];

        TreeNode* newNode = new TreeNode(val);

        newNode->left = constructTree(l, idx - 1, p+1);
        newNode->right = constructTree(idx+1, r, p + (idx-l) + 1);

        return newNode;
    }
};
