/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node* iter = dummy;

        unordered_map<Node*, Node*> old_new;

        Node* h = head;

        while ( h ) {
            iter->next = new Node(h->val);
            iter = iter->next;
            old_new[h] = iter;
            h = h->next;
        }

        iter = dummy->next;
        h = head;
        while ( h ) {
            iter->random = old_new[h->random];
            iter = iter->next;
            h = h->next;
        }

        return dummy->next;
    }
};
