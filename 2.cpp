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
// Time: O(n)
// Space: O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *cur1 = l1, *cur2 = l2, *cur = &dummy;
        int curry = 0;

        while (curry || cur1 || cur2) {
            int num = curry + (cur1 ? cur1->val : 0) + (cur2 ? cur2->val : 0);
            curry = num / 10;
            num = num % 10;
            ListNode *node = new ListNode(num);
            cur->next = node;
            cur = cur->next;
            if (cur1)
                cur1 = cur1->next;
            if (cur2)
                cur2 = cur2->next;
        }
        return dummy.next;
    }
};
