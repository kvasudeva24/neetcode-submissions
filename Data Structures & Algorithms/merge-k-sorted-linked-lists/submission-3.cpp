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
        if ( lists.size() == 0 ) return nullptr;

        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;

        priority_queue<pair<int,ListNode*>> pq;
        for ( auto& h : lists) {
            if ( h != nullptr ) {
                pq.push({-1 * h->val, h});
            }
        }

        while ( !pq.empty() ) {
            auto [_, node] = pq.top(); 
            pq.pop();

            head->next = node;
            head = head->next;
            

            if ( node->next != nullptr ) {
                pq.push({-1 * node->next->val, node->next});
            }

            // head->next = nullptr;
        }
        return dummy->next;
    }
};
