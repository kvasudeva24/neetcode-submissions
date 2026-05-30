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
        for(ListNode* head: lists){
            ListNode* curr = head;
            while(curr){
                q.push({-1 * curr->val, curr});
                curr = curr->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        while(!q.empty()){
            head->next = q.top().second;
            q.pop();
            head = head->next;
        }
        head->next = nullptr;
        return dummy->next;
    }
};
