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

// Time Complexity: O(N) - Each node is processed once, and hashmap lookups are O(1).
// Space Complexity: O(N) - The unordered_map stores O(N) elements, and recursion stack depth is O(N) in the worst case.

class Solution {
public:
    unordered_map<int, int> inorderIndexMap; // Maps node value to its index in inorder traversal
    int postorderIndex; // Tracks the current root index in postorder traversal

    // Recursive helper function to build the tree
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) // Base case: no elements left in this subtree
            return nullptr;
        
        // Pick the current root from postorder (last element is root)
        TreeNode* root = new TreeNode(postorder[postorderIndex--]);

        // Get the index of root in inorder traversal
        int inorderIndex = inorderIndexMap[root->val];

        // Recursively build the right and left subtrees (right first, since postorder is L-R-Root)
        root->right = buildTreeHelper(inorder, postorder, inorderIndex + 1, right);
        root->left = buildTreeHelper(inorder, postorder, left, inorderIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        // Build a hashmap for quick index lookup in inorder array
        for (int i = 0; i < n; i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        // Start from the last index of postorder (root of the tree)
        postorderIndex = n - 1;

        return buildTreeHelper(inorder, postorder, 0, n - 1);
    }
};
