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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = nullptr;
        ListNode* lastRev = nullptr;
        ListNode* iter = head;

        while ( iter ) {
            ListNode* start = iter;
            int i = 1;
            while ( iter && i < k ) {
                iter = iter->next;
                i++;
            }
            if ( !iter ) {
                if ( lastRev ) { lastRev->next = start; }
                break;
            }

            ListNode* newIter = iter->next;
            ListNode* end = iter;


            // cout << start->val << endl;
            // cout << end->val << endl;
            // cout << newIter->val << endl;

            reverseNodes(start, end);
            

            dummy = ( dummy == nullptr ) ? end : dummy;


            if ( !lastRev ) {
                lastRev = start;
            } else {
                lastRev->next = end;
                lastRev = start;
            }

            // cout << lastRev->val << endl;

            iter = newIter;
            // cout << iter->val << endl;
            // return nullptr;
        } 

        return ( !dummy ) ? head : dummy;
    }

    void reverseNodes(ListNode* start, ListNode* end) {
        ListNode* trail = nullptr;
        ListNode* cursor = start;
        ListNode* halt = end->next;
        
        while ( cursor != halt ) {
            ListNode* nxt = cursor->next;
            cursor->next = trail;
            trail = cursor;
            cursor = nxt;
        }

    }
};
