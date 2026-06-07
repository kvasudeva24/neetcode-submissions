class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), val(v) {};
    };


    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    int cap = 0;
    unordered_map<int, Node*> dict;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addNode(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) {
        head = new Node{-1, -1};
        tail = new Node{-1, -1};
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        if ( size == 0 ) { return -1; }

        if ( !dict.count(key) ) { return -1; }

        //key is in the dictionary now we need to get the return value
        int ret = dict[key]->val;

        //remove node
        removeNode(dict[key]);
        addNode(dict[key]);

        return ret;

    }
    
    void put(int key, int value) {
        //does it exist in the map?

        if ( dict.count(key) ) {
            dict[key]->val = value;
            removeNode(dict[key]);
            addNode(dict[key]);
        } else {
            //is size full
            if ( size == cap ) {
                Node* last = tail->prev;
                removeNode(last);
                dict.erase(last->key);
                delete last;
                size--;
            }

            //now we construct a node
            Node* newNode = new Node(key, value);

            //add it to the map and inc size
            dict[key] = newNode;
            size++;

            //addNode to LL
            addNode(newNode);
        }
    }
};
