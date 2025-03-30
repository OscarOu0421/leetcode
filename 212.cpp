/*
Time Complexity (TC):
- Trie Construction: O(N * L), where N = number of words, L = max length of words.
- DFS Traversal: O(m * n * 4^L) in the worst case.

Space Complexity (SC):
- Trie Storage: O(N * L) due to storing words in Trie.
- Recursion Depth: O(L) (backtracking stack).
*/
class TrieNode {
public:
    TrieNode *child[26]; // Pointers to child nodes
    string word;         // Stores the complete word at end nodes

    TrieNode() {
        word = "";  // Empty string means not an end of a word
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    // Insert word into Trie
    void insert(TrieNode *root, const string &word) {
        TrieNode *node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->child[index])
                node->child[index] = new TrieNode();
            node = node->child[index];
        }
        node->word = word; // Store word only at the end node
    }

    // DFS function to search words in the board
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node, vector<string> &ret) {
        int m = board.size();
        int n = board[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '*')
            return;

        char c = board[i][j];
        if (!node->child[c - 'a'])
            return; // No word starts with this prefix
        
        node = node->child[c - 'a'];

        // If a word is found, add to result and clear it to avoid duplicates
        if (!node->word.empty()) {
            ret.push_back(node->word);
            node->word = ""; // Prevent duplicate insertion
        }

        // Mark as visited
        board[i][j] = '*';

        // Explore all four directions
        dfs(board, i + 1, j, node, ret);
        dfs(board, i - 1, j, node, ret);
        dfs(board, i, j + 1, node, ret);
        dfs(board, i, j - 1, node, ret);

        // Restore character for backtracking
        board[i][j] = c;
    }

    // Finds words in the board using the Trie
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = new TrieNode();
        vector<string> ret;

        // Insert words into Trie
        for (const string &word : words) {
            insert(root, word);
        }

        int m = board.size();
        int n = board[0].size();

        // Perform DFS from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, ret);
            }
        }
        return ret;
    }
};

