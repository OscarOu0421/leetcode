// Time: O(n)
// Space: O(h), height of the tree
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
    int postorder(TreeNode *root, int &moves) {
        if (!root)
            return 0;

        /*
         * if we get +3 from left child, means that the left
         * subtree has 3 extra conis to move out.
         * if we get -1 from right child, means that we need to move 
         * 1 coin in. 
         */
        int left = postorder(root->left, moves);
        int right = postorder(root->right, moves);
        // We increase the moves by 4 (3 coins out + 1 coin in)
        moves += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;

        if (!root)
            return 0;

        postorder(root, moves);
        return moves;
    }
};
