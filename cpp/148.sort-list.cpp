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
    ListNode* sortList(ListNode* head) {
        return divideMerge(head);
    }
    

private:
    ListNode* divideMerge(ListNode *node) {
        if (!node || !node->next) return node;
        ListNode *pre = node;
        ListNode *slow = node;
        ListNode *fast = node;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode *sort1 = sortList(node);
        ListNode *sort2 = sortList(slow);
        return mergeTwo(sort1, sort2);
    }
    

    ListNode* mergeTwo(ListNode *l1, ListNode *l2) {
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