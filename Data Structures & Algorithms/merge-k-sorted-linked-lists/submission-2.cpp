/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> q;
        for(auto& head : lists){
            q.push({-1 * head->val, head});
        }

        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(!q.empty()){
            auto [_, node] = q.top(); q.pop();
            cur->next = node;
            if(node->next){
                node = node->next;
                q.push({-1 * node->val, node});
            }
            cur = cur->next;
        }
        cur->next = 0;
        return dummy->next;

    }
};
