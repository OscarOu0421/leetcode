// Time: O(n)
// Space: O(m), m is the maximum level size
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<int> ret;
        int level_size;

        if (!root)
            return ret;

        queue.push(root);
        while (!queue.empty()) {
            level_size = queue.size();
            while (level_size-- > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                if (level_size == 0) {
                    ret.push_back(node->val);
                }
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        return ret;
    }
};
