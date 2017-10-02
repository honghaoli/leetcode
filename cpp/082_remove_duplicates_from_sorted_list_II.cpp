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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode dummy = ListNode(0);
        dummy.next = head;

        ListNode *pre = &dummy;
        ListNode *n = head;
        int dup = head->val - 1;    // not equal to head.val
        bool hasDup = false;
        while (n->next != nullptr) {
            if (n->next->val == n->val) {
                dup = n->val;
                hasDup = true;
            } else if (!hasDup || n->val != dup) {
                pre->next = n;
                pre = n;
            }
            n = n->next;
        }

        if (!hasDup || n->val != dup)
            pre->next = n;
        else
            pre->next = nullptr;

        return dummy.next;
    }
};
