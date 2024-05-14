// Time: O(n) for avg, O(n^2) for worst, becase of hash table.
// Space: O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur = head;
        unordered_map<Node*, Node*> map;    // origin node : new node

        if (!head)
            return NULL;
        
        // construct map
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // redirect next & random pointer to new node
        cur = head;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};
