struct Node {
    map<char, Node*> letters;
    bool end;
    Node(): end(false) {}; 
};




class PrefixTree {
public:
    Node* root = new Node();


    PrefixTree() {}
    
    void insert(string word) {
        Node* cur = root;
        for(char c : word){
            if(cur->letters.count(c)){
                
            } else {
                cur->letters[c] = new Node();
            }
            cur = cur->letters[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char c : word){
            if(!cur->letters.count(c)) return false;
            cur = cur->letters[c];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char c : prefix){
            if(!cur->letters.count(c)) return false;
            cur = cur->letters[c];
        }
        return true;
    }
};
