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
// SC: O(1)
class Solution {
public:
    vector<int> helper(TreeNode *root) {
        if (!root)
            return vector<int>(2, 0);
        /*
         * Maintain the information about 2 scenarios
         * 1. the root is not robbed, then we could rob child or not, so we just max the child.
         * 2. the root is robbed, then we only sum the result of the child is not robbed.
         */
        vector<int> ret(2, 0);
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        
        ret[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ret[1] = root->val + left[0] + right[0];
        return ret;
    } 
    int rob(TreeNode* root) {
        vector<int> ret = helper(root);
        return max(ret[0], ret[1]);
    }
};
