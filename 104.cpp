/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// TC: O(n), Where n is the total number of nodes in the tree.
// SC: O(h) — Where h is the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
