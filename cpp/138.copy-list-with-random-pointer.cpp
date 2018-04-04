/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        if (hash.count(head) == 0) {
            hash[head] = new RandomListNode(head->label);
            hash[head]->next = copyRandomList(head->next);
            hash[head]->random = copyRandomList(head->random);
        }
        return hash[head];
    }

private:
    unordered_map<RandomListNode*, RandomListNode*> hash;
};
