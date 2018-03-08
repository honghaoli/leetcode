
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();    
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *n = root;
        for (auto &c : word) {
            if (!n->next[charToInt(c)]) {
                n->next[charToInt(c)] = new Node();
            }
            n = n->next[charToInt(c)];
        }
        n->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *n = root;
        for (auto &c : word) {
            if (!n->next[charToInt(c)])
                return false;
            n = n->next[charToInt(c)];
        }
        return n->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *n = root;
        for (auto &c : prefix) {
            if (!n->next[charToInt(c)])
                return false;
            n = n->next[charToInt(c)];
        }
        // must have at least one word from this point. 
        return true;
    }
    

private:
    const int R = 26;

    struct Node {
        bool end;
        vector<Node *> next;
        Node() {
            end = false;
            next = vector<Node *>(26, nullptr);
        };
    };
    
    Node *root;
    
    int inline charToInt(char &c) {
        return c - 'a';
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */