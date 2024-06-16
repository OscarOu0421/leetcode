// Time: O(m * n * 4^w + w * h), 
// m, n are the width and length of the board, 
// w is the average length of the words.
// h is the size of the words.
// O(m * n * 4^w) : iterate the board for dfs.
// O(w * h): build Trie Node.

// Space: O(w * h + w)
// O(w * h): Trie Node
// O(w): dfs stack.
class Solution {
    struct TrieNode {
        TrieNode *child[26];
        string word;
        
        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
public:
    TrieNode *buildTrie(vector<string> words) {
        TrieNode *root = new TrieNode();

        for (auto word : words) {
            TrieNode *cur = root;
            for (auto ch : word) {
                int idx = ch - 'a';
                if (cur->child[idx] == NULL)
                    cur->child[idx] = new TrieNode();
                cur = cur->child[idx];
            }
            cur->word = word;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, TrieNode *cur, int i, int j, vector<string> &ret) {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return;
        
        /*
         * if current cell is visited or not int the Trie node.
         */
        if (board[i][j] == '*' || !cur->child[board[i][j] - 'a'])
            return;
        cur = cur->child[board[i][j] - 'a'];
        /* End of one word, add it into result. */
        if (cur->word != "") {
            ret.push_back(cur->word);
            cur->word = "";
        }

        char tmp = board[i][j];
        board[i][j] = '*';
        dfs(board, cur, i+1, j, ret);
        dfs(board, cur, i-1, j, ret);
        dfs(board, cur, i, j-1, ret);
        dfs(board, cur, i, j+1, ret);
        board[i][j] = tmp;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        TrieNode *root = buildTrie(words);
        vector<string> ret;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, root, i, j, ret);
            }
        }
        return ret;
    }
};
