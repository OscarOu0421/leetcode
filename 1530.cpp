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
// TC: O(n * m^2), m is distance, n is the number of node
// SC: O(m)
class Solution {
public:
    vector<int> dfs(TreeNode *root, int distance, int &ret) {
        /* 
         * maintain an array of size is distance
         * root = [1,2,3,null,4], distance = 3
         * left = [0, 0, 1, 0, 0]
         * right = [0, 1, 0, 0, 0]
         * left[2] means there is one leaf node with distance 2 in left subtree.
         */
        vector<int> v(distance + 1, 0);
        if (!root)
            return v;
        
        /*
         * current node is leaf node, for its parent, this leaf node is distance 1
         */
        if (!root->left && !root->right) {
            v[1]++;
            return v;
        }

        /*
         * we can get total number of good node pairs by left[l] * right[r]
         */
        vector<int> left = dfs(root->left, distance, ret);
        vector<int> right = dfs(root->right, distance, ret);
        for (int l = 0; l < left.size(); l++) {
            for (int r = right.size()-1; r >= 0; r--) {
                if (l + r <= distance) {
                    ret += left[l] * right[r];
                }
            }
        }
        /*
         * Before we backtrack to parent, we should add up left and right subtree to
         * return the distance for parent.
         * if a leaf node is at distance i from current node, then it would be at 
         * distance i+1 for parent.
         */
        for (int i = 0; i < v.size()-1; i++) {
            v[i+1] = left[i] + right[i];
        }
        return v;
    }
    int countPairs(TreeNode* root, int distance) {
        int ret = 0;
        dfs(root, distance, ret);
        return ret;
    }
};
