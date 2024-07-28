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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy = ListNode(0, head);
        ListNode *cur = NULL;
        ListNode *prev = &dummy;
        ListNode *next = NULL;

        /*
         * Get the node previous the left 
         * Because it's 1-indexed position, the size should be left - 1
         */
        for (int i = 0; i < left - 1; i++)
            prev = prev->next;
        
        /* Set current node to the left node */
        cur = prev->next;
        /*
         * Because it's 1-indexed position, the size should be right - left
         * reverse the list with size "right - left + 1"
         * For example: 
         * 1 -> 2 -> 3 -> 4 -> 5, left = 2, right = 4
         * prev = 1, cur = 2
         * after reverse current node, the list would be 
         * 1 -> 3 -> 2 -> 4 -> 5
         * 1 -> 4 -> 3 -> 2 -> 5
         */
        for (int i = 0; cur && i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy.next;
    }
};
