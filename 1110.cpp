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
// SC: O(n + m), m is the size of the to_delete
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret;
        unordered_set<int> set;
        
        for (auto val : to_delete)
            set.insert(val);
        helper(root, ret, set, true);
        return ret;
    }
    TreeNode *helper(TreeNode *node, vector<TreeNode*> &ret, unordered_set<int> &set, bool is_root) {
        if (!node)
            return NULL;
        
        /*
         * if current node is root and would not be deleted
         * then add it into result
         */
        bool deleted = set.find(node->val) != set.end();
        if (is_root && !deleted)
            ret.push_back(node);
        
        /*
         * if current is deleted, then its left nad right child would 
         * be "new" root.
         */
        node->left = helper(node->left, ret, set, deleted);
        node->right = helper(node->right, ret, set, deleted);
        return deleted ? NULL : node;
    }
};
