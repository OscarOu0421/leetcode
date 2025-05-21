/*
    Problem: Split Linked List in Parts (LeetCode)
    
    Approach:
        - First, count the total number of nodes in the list (n).
        - Determine the minimum number of nodes in each part: base = n / k.
        - The first (n % k) parts will have one extra node.
        - Iterate through the list and break it into `k` parts accordingly.

    Time Complexity: O(n), where n is the total number of nodes in the linked list.
    Space Complexity: O(k), for storing the head of each resulting part in the return vector.
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;  // Total number of nodes
        vector<ListNode*> ret(k);  // Vector to store result parts
        ListNode* cur = head;

        // Step 1: Count total number of nodes in the list
        while (cur) {
            n++;
            cur = cur->next;
        }

        // Step 2: Determine base size of each part and remainder
        int base = n / k;      // Minimum nodes in each part
        int mod = n % k;       // Extra nodes to distribute

        cur = head;
        for (int i = 0; i < k; i++) {
            int length = base;
            if (mod) {         // Distribute one extra node to this part if any remain
                length++;
                mod--;
            }

            // Step 3: Assign head of this part
            ret[i] = cur;

            // Step 4: Traverse to the last node of the current part
            while (--length && cur) {
                cur = cur->next;
            }

            // Step 5: Cut off the current part and prepare for the next
            if (cur) {
                ListNode* tail = cur;
                cur = cur->next;     // Move to the next part's head
                tail->next = NULL;   // Terminate current part
            }
        }

        return ret;
    }
};

