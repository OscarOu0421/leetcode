/**
 * Time Complexity:
 *   - serialize: O(n), where n is the number of nodes in the tree
 *   - deserialize: O(n), since each node string is processed exactly once
 * 
 * Space Complexity:
 *   - O(n) for the recursion stack and queue used during serialization/deserialization
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string using preorder traversal
    string serialize(TreeNode* root) {
        if (!root)
            return "NULL,";  // Use "NULL" to represent null pointers
        // Serialize current node, then recursively left and right subtree
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        string s = "";             // Temporary string to build each node value
        queue<string> q;          // Queue to hold all node strings in order

        // Split input string by ',' and push each token to the queue
        for (auto c : data) {
            if (c == ',') {
                q.push(s);        // Push completed token to queue
                s = "";           // Reset temp string
                continue;
            }
            s += c;               // Accumulate character into current token
        }

        return helper(q);         // Begin recursive tree reconstruction
    }

private:
    // Helper function to recursively build the tree from queue
    TreeNode* helper(queue<string> &q) {
        string s = q.front();     // Get next node string
        q.pop();                  // Remove it from queue

        if (s == "NULL")          // If it's a NULL marker, return null
            return NULL;

        TreeNode* node = new TreeNode(stoi(s)); // Create node from string
        node->left = helper(q);   // Recur to build left child
        node->right = helper(q);  // Recur to build right child

        return node;              // Return constructed node
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
