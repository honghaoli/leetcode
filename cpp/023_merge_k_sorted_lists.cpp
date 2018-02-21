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





// divide and conquer
class Solution {
public:
    // either priority_queue or divide and conquer would gives O(nklogk) time, where n is the average length of each list, and k is the number of total lists.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
    

private:
    ListNode* mergeKLists(vector<ListNode *> &lists, int start, int end) {
        if (start == end) return lists[start];
        if (start > end) return nullptr;
        int mid = (end - start) / 2 + start;
        ListNode *left = mergeKLists(lists, start, mid);
        ListNode *right = mergeKLists(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }
    

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        else if (l2) cur->next = l2;
        return dummy.next;
    }
};