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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0, head);
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = &dummy;

        /* The 'fast' node is faster n node than 'slow' node */ 
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        /*
         * when the fast node becomes the NULL, that means slow node is nth node from node.
         * and it would be removed.
         */
        prev->next = slow->next;
        return dummy.next;;
    }
};
