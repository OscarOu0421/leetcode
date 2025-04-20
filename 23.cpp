/*
 * Problem: Merge k Sorted Linked Lists
 * Link: LeetCode 23 - https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * Given an array of k linked lists, each sorted in ascending order,
 * merge all the lists into one sorted linked list and return it.
 *
 * Approach:
 * - Use a min-heap (priority_queue with custom comparator) to always select
 *   the smallest current node among the k list heads.
 * - Push the head of each list into the heap.
 * - At each step, pop the smallest node and add it to the merged list.
 * - If the popped node has a next, push that into the heap.
 * - Continue until the heap is empty.
 *
 * Time Complexity: O(N log k)
 *   - N = total number of nodes across all lists.
 *   - Each node is inserted and removed from the heap once, and the heap size is at most k.
 *
 * Space Complexity: O(k)
 *   - The heap stores at most one node from each list.
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap comparator: smallest value has highest priority
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Priority queue (min-heap) to hold nodes by smallest value
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> minq(cmp);

        // Dummy node to build the result list
        ListNode dummy;
        ListNode* cur = &dummy;

        // Push the head of each non-empty list into the heap
        for (auto root : lists) {
            if (root)
                minq.push(root);
        }

        // Extract the smallest node, and push its next (if any) into the heap
        while (!minq.empty()) {
            auto node = minq.top(); // Get the smallest node
            minq.pop();

            if (node->next)
                minq.push(node->next); // Push next node from same list

            cur->next = node; // Add node to the merged list
            cur = cur->next;  // Advance the pointer
        }

        // Return the head of the merged list
        return dummy.next;
    }
};
