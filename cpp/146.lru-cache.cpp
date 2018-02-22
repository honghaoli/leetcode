struct MyListNode {
    int val;
    MyListNode *next;
    MyListNode *prev;
    int key;
    MyListNode(int key, int val) : key(key), val(val), next(NULL), prev(NULL) {}
};


class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        hash.clear();
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        //debug("before get", key);
        if (hash.count(key) > 0) {
            // change current node to the first place, head
            MyListNode * cur = moveFront(key);
            return cur->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //debug("before put", key);
        if (hash.count(key) == 0) {
            MyListNode *node = new MyListNode(key, value);
            if (head) {
                // already has some keys
                head->prev = node;
                node->next = head;
                head = node;
            } else {
                // no items
                head = node;
                tail = node;
            }
            hash[key] = node;
            size++;
            if (size > capacity) {
                MyListNode *tmp = tail;
                tail->prev->next = nullptr;
                hash.erase(tmp->key);
                tail = tmp->prev;
                size--;
                delete tmp;
            }
        } else {
            // already exist
            MyListNode *cur = moveFront(key);
            cur->val = value;
        }
        //debug("after put", key);
    }
    

private:
    int capacity;
    int size;
    unordered_map<int, MyListNode *> hash;
    MyListNode *head, *tail;
    
    MyListNode* moveFront(int key) {
        // change current node to the first place, head
        MyListNode *cur = hash[key];
        if (head != cur) {
            cur->prev->next = cur->next;
            if (!cur->next) 
                tail = cur->prev;
            else
                cur->next->prev = cur->prev;
            cur->prev = nullptr;
            head->prev = cur;
            cur->next = head;
            head = cur;
            //debug("after moveFront", key);
        }
        return cur;
    }
    
    void debug(string str, int key) {
        cout << str << ": key " << key << endl;
        cout << "size: " << size << " " << hash.size() << endl;
        cout << "capacity: " << capacity << endl;
        if (head) {
            cout << "head: " << head->key << " " << head->val << " " << head << endl;
            MyListNode *tmp = head->next;
            while (tmp != tail && tmp) {
                cout << "    : " << tmp->key << " " << tmp->val << " " << tmp << endl;
                tmp = tmp->next;
            }
        }
        if (tail) {
            cout << "tail: " << tail->key << " " << tail->val << " " << tail << endl;
            if (tail->next)
                cout << "tail next: " << tail->next->key << " " << tail->next->val << " " << tail->next << endl;
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */





// use std::list ad the double-linked list
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
    }
    
    int get(int key) {
        //debug("before get", key);
        if (hash.find(key) == hash.end()) return -1;
        dl.splice(dl.begin(), dl, hash[key]);
        hash[key] = dl.begin();
        return hash[key]->second;
    }
    
    void put(int key, int value) {
        //debug("before put", key);
        if (hash.find(key) == hash.end()) {
            // no such item
            dl.emplace_front(key, value);
            hash[key] = dl.begin();
            size++;
            if (size > capacity) {
                auto it = dl.end();
                it--;
                int idx = it->first;
                hash.erase(idx);
                dl.erase(it);
            }
        } else {
            // item already in the list
            dl.splice(dl.begin(), dl, hash[key]);
            hash[key] = dl.begin();
            hash[key]->second = value;
        }
        //debug("after put", key);
    }
    

private:
    int capacity;
    int size;
    list<pair<int, int>> dl;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    
    void debug(string str, int key) {
        cout << str << ": key " << key << endl;
        cout << "size: " << size << " " << hash.size() << endl;
        cout << "capacity: " << capacity << endl;
        for (auto it = dl.begin(); it != dl.end(); it++) {
            cout << "    : " << it->first << " " << it->second << endl;
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */