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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = size(headA);
        int n2 = size(headB);
        if (n1 >= n2) {
            headA = move_ith(headA, n1 - n2);
        } else {
            headB = move_ith(headB, n2 - n1);
        }
        while (headA && headB) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }

private:
    int size(ListNode* node) {
        ListNode *tmp = node;
        int s = 0;
        while (tmp) {
            tmp = tmp->next;
            s++;
        }
        return s;
    }

    ListNode* move_ith(ListNode *node, int i) {
        while (i-- > 0) {
            node = node->next;
        }
        return node;
    }
};
