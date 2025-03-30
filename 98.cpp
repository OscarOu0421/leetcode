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

// Time Complexity: O(N) - We visit each node exactly once.
// Space Complexity: O(H) - Recursive call stack depth is at most the height of the tree (O(log N) for balanced trees, O(N) for skewed trees).

class Solution {
public:
    // Helper function to validate BST using min/max constraints
    bool isValid(TreeNode *node, long minValue, long maxValue) {
        if (!node)
            return true; // An empty node is valid

        // If node's value is outside valid range, it's not a BST
        if (node->val <= minValue || node->val >= maxValue)
            return false;

        // Recursively check left and right subtrees with updated constraints
        return isValid(node->left, minValue, node->val) && 
               isValid(node->right, node->val, maxValue);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
