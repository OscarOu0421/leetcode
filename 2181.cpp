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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy;
        ListNode *cur = head;
        ListNode *curRet = &dummy;

        while (cur) {
            curRet->val += cur->val;
            /*
             * cur->val equls 0 means we would start next value.
             * cur->next means we should not add new node at the end of head.
             */
            if (cur->val == 0 && cur->next) {
                curRet->next = new ListNode(0);
                curRet = curRet->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
