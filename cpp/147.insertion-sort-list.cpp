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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        //dummy.next = head;
        ListNode *cur = head;
        ListNode *pre;
        ListNode *next;
        while (cur) {
            next = cur->next;
            // find the right place for cur
            pre = &dummy;
            while (pre->next && pre->next->val < cur->val) {
                pre = pre->next;
            }
            // insert cur between pre and pre->next
            cur->next = pre->next;
            pre->next = cur;
            // move on to the next node;
            cur = next;
        }
        return dummy.next;
    }
};



// faster one
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pos;
        ListNode *tail;
        ListNode *tmp;
        ListNode *pre = &dummy;
        while (pre->next) {
            if (pre->next->next && pre->next->val > pre->next->next->val) {
                // find the postion for pre->next->next
                pos = &dummy;
                while (pos != pre && pos->next->val < pre->next->next->val) 
                    pos = pos->next;
                // exchange pre->next->next into between pos and pos->next
                tail = pre->next->next->next;
                tmp = pre->next;
                pre->next->next->next = pos->next;
                pos->next = pre->next->next;
                tmp->next = tail;
            } else {
                // move on
                pre = pre->next;
            }
        }
        return dummy.next;
    }
};