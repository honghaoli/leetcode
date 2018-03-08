class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *n = root;
        for (auto &c : word) {
            Node *nex = n->next[charToInt(c)];
            if (!nex)
                nex = new Node();
            n = nex;
        }
        n->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }

private:
    struct Node {
        bool end = false;
        Node *next[26];
    };

    Node *root;

    int inline charToInt(char &c) {
        return c - 'a';
    }

    bool search(string &word, int start, Node *node) {
        if (!node) return false;
        if (start == word.size()) return node->end;
        char &c = word[start];
        if (c != '.') {
            if (!node->next[charToInt(c)])
                return false;
            else
                return search(word, start + 1, node->next[charToInt(c)]);
        } else {
            for (int i = 0; i < 26; i++) {
                if (search(word, start + 1, node->next[i]))
                    return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */