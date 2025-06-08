// This solution generates numbers from 1 to n in lexicographical order
// by performing a DFS-like traversal, building numbers digit by digit.
// Time complexity: O(n), since each number from 1 to n is visited once.

class Solution {
public:
    // Recursive helper function that explores all numbers starting with 'num'
    void helper(int n, vector<int> &ret, int num) {
        if (num > n)
            return;

        ret.push_back(num);  // Add current number to result

        for (int i = 0; i < 10; i++) {
            // Append digit i to the current number and recurse
            helper(n, ret, num * 10 + i);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ret;

        // Start DFS from numbers 1 through 9 (valid starting digits)
        for (int i = 1; i < 10; i++)
            helper(n, ret, i);

        return ret;
    }
};

