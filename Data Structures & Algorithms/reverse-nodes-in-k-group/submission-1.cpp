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
        ListNode* trav = head;
        ListNode* prevTail = nullptr;

        while(trav){
            ListNode* start = trav;
            ListNode* end = trav;
            int i = 0;
            while(end && i < k - 1){
                end = end->next;
                i++;
            }
            if(!end) break;
        
            ListNode* newS = end->next;
            reverseNodes(start, end);
            
            if(!dummy) dummy = end;
            if(prevTail) prevTail->next = end;
            start->next = newS;

            prevTail = start;
            trav = newS;
        }
        return dummy ? dummy : head;
    }

    void reverseNodes(ListNode* start, ListNode* end){
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* stop = end->next;
        while(curr != stop){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    }
};
