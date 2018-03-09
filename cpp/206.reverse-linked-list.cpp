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
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        ListNode *n = head;
        while (n) {
            ListNode *tmp = n->next;
            n->next = dummy.next;
            dummy.next = n;
            n = tmp;
        }
        return dummy.next;
    }
};
