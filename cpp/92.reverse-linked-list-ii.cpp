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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // no need to change if <= 1 node present
        if (head == nullptr || head->next == nullptr) return head;

        ListNode dummy(0);
        dummy.next = head;
        // pre: the node before the first item in the range;
        // start: the first node in the range;
        // last: the last node that has been changed position
        ListNode *pre = &dummy;
        int pos = 0;
        while (pos++ < m - 1) {
            pre = pre->next;
        }
        ListNode *start = pre->next;
        ListNode *last = pre->next;
        ListNode *p = start->next;
        while (n-- > m) {
            start->next = p->next;
            p->next = last;
            pre->next = p;
            last = p;
            p = start->next;
        }

        return dummy.next;
    }
};
