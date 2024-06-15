/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// Time: O(n)
// Space: O(m), m is the max level size of the tree
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        
        if (!root)
            return NULL;
        
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                Node *node = q.front();
                q.pop();
                node->next = levelSize == 0 ? NULL : q.front();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return root;
    }
};
