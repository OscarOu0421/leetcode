/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    // Find the middle of the list (slow ends at the middle node)
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    // Reorder list as per the problem
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find middle
        ListNode* mid = findMiddle(head);

        // Step 2: Reverse second half
        ListNode* second = reverse(mid->next);
        mid->next = nullptr;  // Split the list

        // Step 3: Merge two halves
        ListNode* first = head;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
