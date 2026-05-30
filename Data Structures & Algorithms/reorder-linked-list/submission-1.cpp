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
    void reorderList(ListNode* head) {
        if(!head) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* pivot = slow;
        slow = slow->next;
        pivot->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        int start = 1;
        ListNode* l2 = prev;
        ListNode* l1 = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while(l1 && l2){
            if(start%2){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
            start++;
        }

        if(l1) cur->next = l1;
        if(l2) cur->next = l2;

        head = dummy->next;
    }
};
