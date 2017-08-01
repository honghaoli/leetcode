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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *s = head;
        while (l1 != NULL || l2 != NULL) {
            int sum = carry;
                        
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }      
           
            s->next = new ListNode(sum);
            s = s->next;
        }
        
        if (carry > 0) {
            s->next = new ListNode(carry);
        }
        
        return head->next;
    }
};


/*
 * NOTE:
 * 1. don't forget the last carry;
 * 2. create next new node by first
 *      s->next = new ListNode(num);
 *    then
 *      s = s->next;
 * 3. use a dummy head 0 to make code more concise.
 */

