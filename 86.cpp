// Time Complexity: O(n), where n is the number of nodes in the linked list
// Space Complexity: O(1), only a few pointers are used (no extra data structures)

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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy heads for two separate lists: <x and >=x
        ListNode* dummy1 = new ListNode();
        ListNode* dummy2 = new ListNode();
        ListNode* cur1 = dummy1;  // Pointer for <x list
        ListNode* cur2 = dummy2;  // Pointer for >=x list
        ListNode* cur = head;

        // Traverse the original list and distribute nodes into two lists
        while (cur) {
            if (cur->val < x) {
                cur1->next = cur;
                cur1 = cur1->next;
            } else {
                cur2->next = cur;
                cur2 = cur2->next;
            }

            // Save next node and disconnect current to avoid cycles
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
        }

        // Connect the <x list to the >=x list
        cur1->next = dummy2->next;

        // Return the head of the merged list (skip dummy1)
        return dummy1->next;
    }
};
