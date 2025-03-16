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
// TC: O(m * n) — In the worst case, for each node in tree s, we may compare it with all nodes in tree t.
// SC: O(max(m, n)) — Due to recursion stack depth.
class Solution {
public:
    bool dfs(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        return root->val == subRoot->val && dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        return dfs(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
