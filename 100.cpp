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
// TC: O(n), Where n is the total number of nodes in the trees.
// SC: O(h), Where h is the height of the tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (p && q && p->val == q->val) {
            return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
        }
        return false;
    }
};
