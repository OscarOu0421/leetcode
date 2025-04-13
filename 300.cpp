/*
 * Time Complexity: O(n log n)
 *   - For each of the n elements, binary search takes O(log n)
 * Space Complexity: O(n)
 *   - In the worst case, `list` can grow to size n
 */

class Solution {
public:
    // Custom binary search: returns the first index in `list` where list[idx] >= num
    int bsearch(vector<int> list, int num) {
        int l = 0;
        int r = list.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (list[m] == num)
                return m;
            else if (list[m] > num)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> list;

        for (int num : nums) {
            if (list.empty() || list.back() < num)
                list.push_back(num); // Extend LIS
            else {
                int idx = bsearch(list, num); // Find position to replace
                list[idx] = num;              // Replace with smaller value
            }
        }

        return list.size(); // Length of longest increasing subsequence
    }
};
