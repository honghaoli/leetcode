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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *last = head;
        for (int i = 0; i < n; i++) {
            if (last == nullptr)        // in case of n > size of list, the test case has this one!
                return head->next;
            last = last->next;
        }
        ListNode *nth = head;
        ListNode *pre_nth = head;
        while (last != nullptr) {
            last = last->next;
            pre_nth = nth;
            nth = nth->next;
        }

        if (nth == head)
            return head->next;

        pre_nth->next = nth->next;
        return head;
    }
};
