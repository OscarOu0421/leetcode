// Time Complexity: O(n) — Each node is visited at most twice (once directly, once via its predecessor).
// Space Complexity: O(1) — In-place modification, no extra space is used beyond pointers.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                // Find the rightmost node in the left subtree (predecessor)
                TreeNode* pred = curr->left;
                while (pred->right)
                    pred = pred->right;

                // Connect the right subtree to the right of predecessor
                pred->right = curr->right;

                // Move the left subtree to the right side
                curr->right = curr->left;
                curr->left = nullptr;  // set left to NULL as required
            }

            // Move to the next right node (flattened path)
            curr = curr->right;
        }
    }
};
