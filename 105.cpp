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

// Time Complexity: O(N) - Each node is processed once, and the hashmap allows O(1) lookup.
// Space Complexity: O(N) - The unordered_map stores O(N) elements, and the recursion stack depth is O(N) in the worst case.

class Solution {
public:
    unordered_map<int, int> map; // Stores the index of each value in inorder traversal
    int preorder_index = 0; // Keeps track of the current root in preorder traversal

    // Recursive helper function to build the tree
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int l, int r) {
        if (l > r) // Base case: no elements left in this subtree
            return nullptr;
        
        // Select the current root from preorder
        TreeNode *root = new TreeNode(preorder[preorder_index++]);
        
        // Find the index of the root in inorder traversal
        int pos = map[root->val];

        // Recursively build the left and right subtrees
        root->left = build(preorder, inorder, l, pos - 1);
        root->right = build(preorder, inorder, pos + 1, r);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        // Store indices of inorder values in a hash map for quick lookup
        for (int i = 0; i < n; i++)
            map[inorder[i]] = i;

        return build(preorder, inorder, 0, n - 1);
    }
};
