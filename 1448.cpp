// Time Complexity: O(n), where n is the number of nodes in the tree
// Space Complexity: O(h), where h is the height of the tree (due to recursion stack)
//     - Worst case: O(n) for a skewed tree
//     - Best/Average case: O(log n) for a balanced tree

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
    // Helper function to traverse the tree and count good nodes
    void helper(TreeNode *node, int maxValue, int &ret) {
        if (!node) // Base case: null node
            return;
        
        // Update maxValue seen so far along the path
        maxValue = max(maxValue, node->val);

        // If current node's value is greater than or equal to all ancestors, count it
        if (node->val == maxValue)
            ret++;

        // Recurse on left and right subtrees with updated maxValue
        helper(node->left, maxValue, ret);
        helper(node->right, maxValue, ret);
    }

    // Main function to be called with the root of the tree
    int goodNodes(TreeNode* root) {
        int ret = 0; // Counter for good nodes
        helper(root, INT_MIN, ret); // Start traversal with minimal initial maxValue
        return ret;
    }
};
