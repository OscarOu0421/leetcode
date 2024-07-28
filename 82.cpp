/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool isuniq(ListNode *prev, ListNode *cur) {
        /*
         * 1. the previous value is not equals to the current value
         * 2. the next value is not equals to the current value or 
         *    the next node is NULL pointer
         */
        return prev->val != cur->val && ((cur->next && cur->next->val != cur->val) || cur->next == NULL);
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(-101, head);
        ListNode *cur = head;
        ListNode *prev = &dummy;
        ListNode *uniq = &dummy;

        while (cur) {
            /* If the current node is unique, then we connect it! */
            if (isuniq(prev, cur)) {
                uniq->next = cur;
                uniq = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        /*
         * For example: list=[1, 1]
         * the whole list should be removed, the next of the last unique node should be NULL pointer
         */
        uniq->next = NULL;
        return dummy.next;
    }
};
