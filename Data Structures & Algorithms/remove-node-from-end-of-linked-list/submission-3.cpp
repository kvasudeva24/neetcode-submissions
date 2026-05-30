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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* marker = head;
        int iter = 0;
        while(iter < n){
            marker = marker->next;
            iter++;
        }
        ListNode* trail = head;
        while(marker && marker->next){
            marker = marker->next;
            trail = trail->next;
        }

        if(trail == head && !marker) return head->next;

        trail->next = (trail->next) ? trail->next->next : nullptr;       

        return head;
    }
};
