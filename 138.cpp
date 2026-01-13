/*
Time Complexity: O(n)
- Each node is visited and copied exactly once.

Space Complexity: O(n)
- Hash map stores a mapping for each original node.
- Recursion stack can grow up to n in the worst case.
*/

class Solution {
public:
    // Map original node to its copied node
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {
        // Base case: empty node
        if (!head)
            return nullptr;

        // If the node has already been copied, return it
        if (mp.count(head))
            return mp[head];

        // Create a new copy of the current node
        Node* copy = new Node(head->val);

        // Save the mapping before recursive calls (important!)
        mp[head] = copy;

        // Recursively copy next and random pointers
        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);

        return copy;
    }
};

/*
Time Complexity: O(n)
- Three linear passes over the list.

Space Complexity: O(1)
- No extra data structures are used (excluding output list).
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        Node* cur = head;

        // Step 1: Create new nodes and insert them after original nodes
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // Step 2: Assign random pointers for copied nodes
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // Step 3: Separate the original list and the copied list
        cur = head;
        Node* newHead = head->next;

        while (cur) {
            Node* copy = cur->next;
            cur->next = copy->next;
            copy->next = (copy->next) ? copy->next->next : nullptr;
            cur = cur->next;
        }

        return newHead;
    }
};
