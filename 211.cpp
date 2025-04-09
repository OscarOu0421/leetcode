// Time Complexity:
//  - addWord: O(n), where n is the length of the word
//  - search: Worst case O(26^d * n), where d is the number of '.' characters and n is the word length
//
// Space Complexity: O(m * n), where m is the number of words and n is the average word length

class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26] = {};  // Pointers to children (one for each lowercase letter)
        bool isEnd = false;           // True if a word ends at this node
    };

    TrieNode* root;                   // Root of the Trie

public:
    WordDictionary() {
        root = new TrieNode();        // Initialize the root node
    }

    // Adds a word to the Trie
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';                      // Convert char to index
            if (!node->children[idx])               // Create node if it doesn't exist
                node->children[idx] = new TrieNode();
            node = node->children[idx];             // Move to the child
        }
        node->isEnd = true;                         // Mark end of the word
    }

    // Searches for a word with optional '.' wildcards
    bool search(string word) {
        return dfs(word, 0, root);                  // Start DFS from the root
    }

private:
    // Helper function to perform DFS for search with '.'
    bool dfs(const string& word, int index, TrieNode* node) {
        if (!node) return false;                    // Dead end
        if (index == word.size()) return node->isEnd; // Reached end, check if it's a valid word

        char c = word[index];
        if (c == '.') {
            // Try all possible children if current char is '.'
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && dfs(word, index + 1, node->children[i]))
                    return true;
            }
            return false; // No valid path
        } else {
            // Normal character, go to the corresponding child
            return dfs(word, index + 1, node->children[c - 'a']);
        }
    }
};
