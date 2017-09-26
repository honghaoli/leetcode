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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        
        ListNode *n1 = head;
        
        int length = 0;
        while (n1 != nullptr) {
            n1 = n1->next;
            length++;
        }
        
        k = k % length;
        
        n1 = head;
        while (k-- > 0) {
            n1 = n1->next;
        }
        if (n1 == head) return head;
        
        ListNode *pre = head, *n2 = head;
        int p = 0;
        while (n1 != nullptr) {
            n1 = n1->next;
            n2 = n2->next;
            if (p++ > 0)
                pre = pre->next;
        }
        
        pre->next = nullptr;
        pre = head;
        head = n2;
        while (n2->next != nullptr)
            n2 = n2->next;
        
        n2->next = pre;
        
        return head;
    }
};
