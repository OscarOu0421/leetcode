// Time: O(n)
// Space: O(n)
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
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, 
    int &rootidx, int l, int r, unordered_map<int, int> &map) {
        if (l > r)
            return NULL;
        
        int pivot = map[postorder[rootidx]];
        rootidx--;
        TreeNode *node = new TreeNode(inorder[pivot]);
        node->right = build(inorder, postorder, rootidx, pivot+1, r,  map);
        node->left = build(inorder, postorder, rootidx, l, pivot-1, map);
        
        return node; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        int n = inorder.size();
        int rootidx = n-1;

        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }
        return build(inorder, postorder, rootidx, 0, n-1, map);
    }
};
