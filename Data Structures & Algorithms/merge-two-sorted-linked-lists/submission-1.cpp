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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* iterA = list1;
        ListNode* iterB = list2;

        ListNode* base = new ListNode(-1);
        ListNode* newIter = base;

        while ( iterA && iterB ) {
            if ( iterA->val < iterB->val ) {
                newIter->next = iterA;
                iterA = iterA->next;
                newIter = newIter->next;
            } else {
                newIter->next = iterB;
                iterB = iterB->next;
                newIter = newIter->next;
            }
        }

        while ( iterA ) {
            newIter->next = iterA;
            iterA = iterA->next;
            newIter = newIter->next;
        }

        while ( iterB ) {
            newIter->next = iterB;
            iterB = iterB->next;
            newIter = newIter->next;
        }

        return base->next;

    }
};
