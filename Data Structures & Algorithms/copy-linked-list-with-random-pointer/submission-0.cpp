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
        unordered_map<Node*, Node*> old_new;

        Node* dummy = new Node(-1);
        Node* first = dummy;
        Node* iter = head;

        while(iter != nullptr){
            Node* newNode = new Node(iter->val);
            first->next = newNode;
            old_new[iter] = newNode;
            iter = iter->next;
            first = first->next;
        }

        iter = head;
        Node* second = dummy->next;
        while(iter!=nullptr){
            second->random = old_new[iter->random];
            second = second->next;
            iter = iter->next;
        }
        return dummy->next;

    }
};
