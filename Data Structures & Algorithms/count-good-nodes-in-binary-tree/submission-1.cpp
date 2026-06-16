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
        if ( !root ) return 0;

        int counter = 0;
        trackGood(root, root->val, root->val, counter);
        return counter;
    }

    void trackGood(TreeNode* v, int root, int curMax, int& counter) {
        if ( !v ) return;

        if ( (root <= v->val) && (v->val >= curMax) ) {
            cout << v->val << endl;
            counter++;
        }


        trackGood(v->left, root, max(curMax, v->val), counter);
        trackGood(v->right, root, max(curMax, v->val), counter);
        
    }

};
