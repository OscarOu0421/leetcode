// Time Complexity: O(N + M + K * α(26))
//   - N = length of s1/s2 (used in union)
//   - M = length of baseStr (used in find)
//   - K = number of characters in baseStr (worst case K = M)
//   - α(26) = inverse Ackermann function, nearly constant for 26 characters
// Space Complexity: O(1)
//   - Uses a fixed-size unordered_map for 26 lowercase letters

class Solution {
public:
    unordered_map<char, char> parent;

    // Find the representative (root) of character c with path compression
    char find(char c) {
        if (parent[c] != c) {
            parent[c] = find(parent[c]);  // Path compression
        }
        return parent[c];
    }

    // Union two sets by assigning the smaller lexicographical character as the parent
    void unionset(char a, char b) {
        char pa = find(a);
        char pb = find(b);
        if (pa < pb)
            parent[pb] = pa;
        else
            parent[pa] = pb;
    }

    // Builds the smallest equivalent string by applying DSU logic
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int size = min(s1.size(), s2.size());
        string ret = "";

        // Initialize parent for all lowercase letters
        for (int i = 0; i < 26; i++) {
            parent['a' + i] = 'a' + i;
        }
        
        // Union each pair of equivalent characters
        for (int i = 0; i < size; i++) {
            unionset(s1[i], s2[i]);
        }

        // Build the resulting string using smallest equivalent characters
        for (auto c : baseStr) {
            ret += find(c);
        }
        return ret;
    }
};

