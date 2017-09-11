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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *result = head->next;
        while (first != nullptr && second != nullptr) {
            pre->next = second;
            first->next = second->next;
            second->next = first;
            //
            pre = first;
            //
            first = first->next;
            if (first == nullptr)
                break;
            second = first->next;
        }

        return result;
    }
};
