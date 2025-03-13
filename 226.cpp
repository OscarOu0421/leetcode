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
// TC: O(n)
// SC: O(h)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *r;
        TreeNode *l;

        if (!root)
            return NULL;

        l = invertTree(root->left);
        r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};
