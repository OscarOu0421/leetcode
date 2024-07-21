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
    bool dfs(TreeNode *root, int val, string &ret) {
        if (!root)
            return false;
        if (root->val == val)
            return true;
        if (dfs(root->left, val, ret))
            ret.push_back('L');
        if (dfs(root->right, val, ret))
            ret.push_back('R');
        return !ret.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string sPath, dPath;
        /*
         * Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
         * Step 1: Get path from root to start and dest
         * So we get "LL" and "RL"
         */
        dfs(root, startValue, sPath);
        dfs(root, destValue, dPath);
        
        /* 
         * Step 2: Remove common prefix path
         */
        while (!sPath.empty() && !dPath.empty() && sPath.back() == dPath.back()) {
            sPath.pop_back();
            dPath.pop_back();
        }
        /*
         * Step 3: Replace all steps in the start path to "U" and add dest path
         */
        reverse(dPath.begin(), dPath.end());
        return string(sPath.size(), 'U') + dPath;
    }
};
