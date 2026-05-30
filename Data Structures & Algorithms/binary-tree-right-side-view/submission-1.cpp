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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> q; q.push_front(root);

        vector<int> ans;
        if(!root) return ans;

        while(!q.empty()){
            ans.push_back(q.back()->val);
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode*& cur = q.front();
                q.pop_front();
                if(cur->left) q.push_back(cur->left);
                if(cur->right) q.push_back(cur->right);
            }
        }
        return ans;
    }
};
