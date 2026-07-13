/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> oldNew;

    Node* cloneGraph(Node* node) {
        if ( !node ) { return node; }


        Node* newNode = new Node(node->val);
        oldNew[node] = newNode;
        cloneOldNodes(node, newNode);
        return newNode;

    }

    void cloneOldNodes(Node* oldNode, Node* newNode) {

        for ( Node* nbor : oldNode->neighbors) {
            //have we seen nbor so far?
            // yes --> skip
            // no --> explore

            if ( !oldNew.count(nbor) ) {
                Node* newNbor = new Node(nbor->val);
                oldNew[nbor] = newNbor;
                newNode->neighbors.push_back(newNbor);
                cloneOldNodes(nbor, newNbor);
            } else {
                newNode->neighbors.push_back(oldNew[nbor]);
            }
        }

    }
};
