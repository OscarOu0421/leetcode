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

// Time Complexity: O(n), where n is the number of nodes in the tree
// Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

class Solution {
public:
    // Helper function that returns the max gain from this subtree, and updates global max path sum
    int helper(TreeNode* root, int &maxSum) {
        if (!root) return 0;

        // Recursively compute max gains from left and right, ignore negative paths
        int leftGain = max(helper(root->left, maxSum), 0);
        int rightGain = max(helper(root->right, maxSum), 0);

        // Local path sum using current node as the highest node
        int localMax = root->val + leftGain + rightGain;

        // Update global max path sum
        maxSum = max(maxSum, localMax);

        // Return max gain if continuing the path upward (only one child can be taken)
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize to smallest possible value
        helper(root, maxSum);
        return maxSum;
    }
};
