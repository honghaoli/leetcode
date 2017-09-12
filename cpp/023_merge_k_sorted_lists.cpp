/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(0);
        ListNode *l = dummy;
        auto cmp = [](ListNode *left, ListNode *right) { return left->val > right->val;};
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pqueue(cmp);
        for (auto &pl : lists) {
            if (pl != nullptr) {
                pqueue.push(pl);
            }
        }
        
        ListNode *tmp;
        while (!pqueue.empty()) {
            tmp = pqueue.top();
            pqueue.pop();
            l->next = tmp;
            l = l->next;
            tmp = tmp->next;
            if (tmp != nullptr)
                pqueue.push(tmp);
        }
        
        return dummy->next;
    }
};
