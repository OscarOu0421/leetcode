// Time Complexity: O(n), where n is the number of nodes in the BST (worst-case traversal of entire tree)
// Space Complexity: O(n), for storing inorder traversal in vector `v`

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
    // Performs inorder traversal and collects node values in sorted order
    void inorder(TreeNode *node, vector<int> &v) {
        if (!node)
            return;
        inorder(node->left, v);       // Traverse left subtree
        v.push_back(node->val);       // Visit current node
        inorder(node->right, v);      // Traverse right subtree
    }

    // Returns the k-th smallest element (1-indexed) in BST
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;                // To store inorder traversal
        inorder(root, v);            // Fill vector with sorted node values
        return v[k-1];                // Return the (k-1)th element (0-indexed)
    }
};
