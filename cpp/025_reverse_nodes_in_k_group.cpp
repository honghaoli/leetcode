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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1)
            return head;
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *pre = dummy;
        ListNode *nex = dummy;
        ListNode *start = dummy;
        ListNode *end = dummy;
        
        while (end != nullptr) {
            // find all the k nodes.
            int count = k;
            pre = start;
            end = start;
            start = pre->next;
            while (count > 0) {
                if (end == nullptr) break;
                end = end->next;
                count--;
            }
            if (end == nullptr) break;
            nex = end->next;
            
            // reverse all the k nodes.
            ListNode *tmp_start = start;
            ListNode *tmp_insert = start->next;
            while (start->next != nex) {
                ListNode *tmp = tmp_insert->next;
                tmp_insert->next = tmp_start;
                pre->next = tmp_insert;
                start->next = tmp;
                tmp_insert = tmp;
                tmp_start = pre->next;
            }
        }
        
        return dummy->next;
    }
};
