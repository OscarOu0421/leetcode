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
// SC: O(n)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map;
        unordered_map<int, bool> ischild;
        TreeNode *root;
        
        /*
         * map: key: node value, value: node pointer
         * ischild: key: node value, value: is child or not
         */
        for (auto desc : descriptions) {
            if (map.find(desc[0]) == map.end()) {
                map[desc[0]] = new TreeNode(desc[0]);
            }
            if (map.find(desc[1]) == map.end()) {
                map[desc[1]] = new TreeNode(desc[1]);
            }
            if (desc[2])
                map[desc[0]]->left = map[desc[1]];
            else
                map[desc[0]]->right = map[desc[1]];
            ischild[desc[1]] = true;
        }
        for (auto desc : descriptions) {
            if (!ischild[desc[0]]) {
                root = map[desc[0]];
                break;
            }
        }
        return root;
    }
};
