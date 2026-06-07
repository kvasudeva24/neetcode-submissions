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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cin = 0;

        ListNode* dummy = new ListNode{-1};
        ListNode* iter = dummy;

        while ( l1 && l2 ) {
            int sum = l1->val + l2->val + cin;

            cin = sum / 10;
            sum %= 10;

            iter->next = new ListNode(sum);
            iter = iter->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while ( l1 ) {
            int sum = l1->val + cin;

            cin = sum / 10;
            sum %= 10;

            iter->next = new ListNode(sum);
            iter = iter->next;

            l1 = l1->next;
        }

        while ( l2 ) {
            int sum = l2->val + cin;

            cin = sum / 10;
            sum %= 10;

            iter->next = new ListNode(sum);
            iter = iter->next;

            l2 = l2->next;
        }
        
        if ( !l1 && !l2 && cin ) {
            iter->next = new ListNode(cin);
        }

        return dummy->next;


    }
};
