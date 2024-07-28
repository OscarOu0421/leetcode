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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *ret = NULL;
        int n = 0;

        if (head == NULL)
            return ret;
        /*
         * if the size of the list is 3, and k is 5
         * then we only need to rotate k % n = 2
         */
        while (fast) {
            fast = fast->next;
            n++;
        }
        k = k % n;
        if (k == 0)
            return head;

        /*
         * fast node is faster k node distance than slow node
         */
        fast = head;
        while (k--) {
            fast = fast->next;
        }
        /*
         * For example: list=[1, 2, 3, 4, 5], k = 2
         * After while loop, the fast node is 5, and slow node is 3
         */
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        /*
         * the next of the slow node would be new head
         * the slow node would be the last node
         * the fast node would connect to the original head
         */
        ret = slow->next;
        slow->next = NULL;
        fast->next = head;
        return ret;
    }
};
