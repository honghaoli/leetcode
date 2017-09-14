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
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *p1 = head;
        ListNode *p2 = head;

        while (p2 != nullptr) {
            p2 = p2->next;
            if (p2 == nullptr) break;
            if (p2->val != p1->val) {
                p1->next = p2;
                p1 = p2;
            }
        }
        p1->next = nullptr;

        return head;
    }
};
