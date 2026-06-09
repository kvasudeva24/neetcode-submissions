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
        if ( !head ) return; 
        if ( !head->next ) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while ( fast->next && fast->next->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }   

        if ( fast->next ) { fast = fast->next; }

        cout << fast->val << endl;
        cout << slow->val << endl;
    

        ListNode* secondHead = slow->next;
        slow->next = nullptr;
        reverseNodes(secondHead, fast);

        ListNode* l1 = head;
        ListNode* l2 = fast;
        ListNode* dummy = new ListNode(-1);
        ListNode* iter = dummy;

        int i = 1;
        while ( l1 && l2 ) {
            if ( i % 2 == 0 ) {
                iter->next = l2;
                l2 = l2->next;
                iter = iter->next;
            } else {
                iter->next = l1;
                l1 = l1->next;
                iter = iter->next;
            }
            i++;
        }

        if ( l1 ) { iter->next = l1; }
        if ( l2 ) { iter->next = l2; }

        head = dummy->next;
        delete dummy;
        return;
    }

    void reverseNodes(ListNode* start, ListNode* end) {
        ListNode* iter = start;
        ListNode* trail = nullptr;
        while ( iter ) {
            ListNode* nxt = iter->next;
            iter->next = trail;
            trail = iter;
            iter = nxt;
        }
    }
};
