/*
 * Time Complexity: O(n)      // Each node is visited exactly once
 * Space Complexity: O(h)     // Stack space used for DFS traversal (h = tree height)
 */

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
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> sk;  // Stack for DFS: stores node and current number formed so far
        int sum = 0;                     // Final sum of all root-to-leaf numbers

        if (!root)
            return sum;                 // Edge case: empty tree
        
        sk.push({root, 0});             // Start DFS with root node and initial number 0

        while (!sk.empty()) {
            auto [node, cur] = sk.top(); // Get current node and the number so far
            sk.pop();

            cur = cur * 10 + node->val;  // Append current node's value to number
            
            // If left child exists, push it onto the stack with updated number
            if (node->left)
                sk.push({node->left, cur});
            
            // If right child exists, push it onto the stack with updated number
            if (node->right)
                sk.push({node->right, cur});
            
            // If it's a leaf node, add the number to total sum
            if (!node->left && !node->right) {
                sum += cur;
            }
        }

        return sum;  // Return total sum of all root-to-leaf numbers
    }
};
