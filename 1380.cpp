// TC: O(n^2)
// SC: O(n)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m, INT_MAX);
        vector<int> cols(n, INT_MIN);
        vector<int> ret;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] = min(rows[i], matrix[i][j]);
                cols[j] = max(cols[j], matrix[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] == cols[j])
                    ret.push_back(rows[i]);
            }
        }
        return ret;
    }
};
