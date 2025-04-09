// Time Complexity: O(n), where n is the number of nodes in the tree (must explore entire tree in worst case)
// Space Complexity: O(h), where h is the height of the tree (due to recursion stack)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    // General binary tree LCA function (doesn't require BST properties)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root; // If current node is null or matches one of the targets, return it

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right returned non-null, current node is the LCA
        if (left && right)
            return root;

        // Otherwise, return whichever side is non-null
        return left ? left : right;
    }
};
