/**
 * Time Complexity: O(n)
 *   - Each tree node is visited exactly once.
 *
 * Space Complexity: O(w)
 *   - w is the maximum width of the binary tree.
 *   - In the worst case (complete binary tree), w = O(n).
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;        // Stores the final level order traversal

        queue<TreeNode*> q;                // Queue used for BFS traversal

        // If the tree is empty, return an empty result
        if (!root)
            return result;

        // Push the root node into the queue
        q.push(root);

        // Continue BFS until there are no more nodes to process
        while (!q.empty()) {
            vector<int> level;             // Stores values for the current level

            int size = q.size();           // Number of nodes in the current level

            // Process all nodes in the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // Get the front node from the queue
                q.pop();                    // Remove the node from the queue

                level.push_back(node->val); // Add the node's value to the current level

                // If the left child exists, add it to the queue
                if (node->left)
                    q.push(node->left);

                // If the right child exists, add it to the queue
                if (node->right)
                    q.push(node->right);
            }

            // Add the current level to the final result
            result.push_back(level);
        }

        // Return the complete level order traversal
        return result;
    }
};

