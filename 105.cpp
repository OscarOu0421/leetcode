// Time: O(n)
// Space:O(n)
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
    TreeNode *build(vector<int> &preorder, vector<int>& inorder, int &rootidx, int l, int r, unordered_map<int, int> &map) {
        if (l > r)
            return NULL;

        int pivot = map[preorder[rootidx]];
        rootidx++;
        // inorder[pivot] = preorder[rootidx]
        TreeNode *node = new TreeNode(inorder[pivot]);
        node->left = build(preorder, inorder, rootidx, l, pivot-1, map);
        node->right = build(preorder, inorder, rootidx, pivot+1, r, map);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootidx = 0;
        unordered_map<int, int> map;
        for (int i = 0;i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return build(preorder, inorder, rootidx, 0, inorder.size()-1, map);
    }
};
