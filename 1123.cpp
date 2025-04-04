// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(h) where h is the height of the tree (due to recursion stack)

class Solution {
public:
    // Helper function returns a pair: {max depth from this node, LCA at that depth}
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) 
            return {0, nullptr}; // Base case: empty node has depth 0 and no LCA

        // Recurse on the left and right children
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        // If left subtree is deeper, propagate its depth and LCA up
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        } 
        // If right subtree is deeper, propagate its depth and LCA up
        else if (right.first > left.first) {
            return {right.first + 1, right.second};
        } 
        // If both are equal, current node is the LCA of deepest leaves
        else {
            return {left.first + 1, node};
        }
    }

    // Main function to find LCA of deepest leaves
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second; // Return only the LCA from the dfs result
    }
};
