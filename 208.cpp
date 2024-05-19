// Time:  O(n) for insert, search, startsWith, n is the length of wht word
// Space: O(26n)

class TrieNode {
public:
    bool endWord;
    TrieNode *child[26];
    TrieNode() {
        endWord = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for (auto c : word) {
            int i = c - 'a';
            if (cur->child[i] == NULL) {
                cur->child[i] = new TrieNode();
            }
            cur = cur->child[i];
        }
        cur->endWord = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for (auto c : word) {
            int i = c - 'a';
            // Not even reach the end of the word
            if (cur->child[i] == NULL)
                return false;
            cur = cur->child[i];
        }
        // Reach the end of the word, then check the word is exist
        // or not at cur position.
        return cur->endWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto c : prefix) {
            int i = c - 'a';
            // Not reach the end of the prefix
            if (cur->child[i] == NULL)
                return false;
            cur = cur->child[i];
        }
        return true;
    }

    void clear(TrieNode *root) {
        for (int i = 0; i < 26; i++) {
            if (root->child[i])
                clear(root->child[i]);
        }
        delete root;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
