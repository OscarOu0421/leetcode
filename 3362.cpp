// Time Complexity: O(q log q + n log q)
//   - q = number of queries, n = size of nums
//   - Sorting queries: O(q log q)
//   - Each query is pushed/popped once in priority queues: O(q log q)
//   - Overall iteration over nums: O(n log q)
// Space Complexity: O(q)
//   - Due to the priority queues used to manage candidate and chosen queries

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> candidate; // Max-heap: stores end indices of unused queries starting at or before current index
        priority_queue<int, vector<int>, greater<int>> chosen; // Min-heap: tracks active queries ending at or after current index
        int ret = 0; // Count of queries used (i.e., not removed)
        int n = nums.size();

        sort(queries.begin(), queries.end()); // Sort queries by start index for sequential processing

        for (int i = 0, j = 0; i < n; i++) {
            // Push all queries starting at index i into candidate heap
            while (j < queries.size() && queries[j][0] == i) {
                candidate.push(queries[j][1]); // push end index of query
                j++;
            }

            // Each active query reduces current value by 1
            nums[i] -= chosen.size();

            // If more decrements are needed, use queries from candidate heap
            while (nums[i] > 0 && !candidate.empty() && candidate.top() >= i) {
                ret++; // using one more query
                chosen.push(candidate.top()); // move it to chosen set
                candidate.pop();
                nums[i]--;
            }

            // If we can't decrement nums[i] to 0, return -1
            if (nums[i] > 0)
                return -1;

            // Remove expired queries whose range ends at current index
            while (!chosen.empty() && chosen.top() == i) {
                chosen.pop();
            }
        }

        // Return number of queries that can be removed
        return queries.size() - ret;
    }
};

