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
// Time: O(n), n is the number of nodes
// Space: O(1)
class Solution {
public:
    int preorder(TreeNode *root, int depth) {
        if (!root)
            return depth;
        
        depth++;
        int left = preorder(root->left, depth);
        int right = preorder(root->right, depth);
        return (left > right) ? left : right;
    }
    int maxDepth(TreeNode* root) {
        return preorder(root, 0);
    }
};
