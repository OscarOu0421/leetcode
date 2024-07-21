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
    TreeNode *getlca(TreeNode *root, int start, int dest) {
        if (!root)
            return NULL;
        
        if (root->val == start || root->val == dest)
            return root;
        
        TreeNode *left = getlca(root->left, start, dest);
        TreeNode *right = getlca(root->right, start, dest);
        
        if (left && right)
            return root;
        return left ? left : right;
    }
    bool dfs(TreeNode *root, int val, string &path) {
        if (!root)
            return false;
        if (root->val == val)
            return true;

        path.push_back('L');
        if (dfs(root->left, val, path))
            return true;
        path.pop_back();
            
        path.push_back('R');
        if (dfs(root->right, val, path))
            return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string sPath, dPath;
        
        /*
         * Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
         * Step 1: get lowest common ancestor(lca)
         */
        TreeNode *lca = getlca(root, startValue, destValue);
        /*
         * Step 2: Get path from lca to start and dest
         * So we get "LL" and "RL"
         */
        dfs(lca, startValue, sPath);
        dfs(lca, destValue, dPath);

        /*
         * Step 3: convert all lca to start path into 'U', since we would move upward
         */
        return string(sPath.size(), 'U') + dPath;
    }
};
