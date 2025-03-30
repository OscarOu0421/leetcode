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

// Time Complexity: O(N) - Each node is processed once.
// Space Complexity: O(N) - At worst, the queue holds all nodes in the last level (O(N) for a full binary tree).

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> ret;
        
        if (!root)
            return ret;

        q.push(root);
        while (!q.empty()) {
            int count = q.size();  // Number of nodes at the current level
            vector<int> level;     // Stores the current level's values

            for (int i = 0; i < count; i++) {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            
            ret.push_back(level);
        }
        return ret;
    }
};
