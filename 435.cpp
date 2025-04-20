/*
 * Problem: Non-overlapping Intervals
 * Link: LeetCode 435 - https://leetcode.com/problems/non-overlapping-intervals/
 *
 * Given a list of intervals, the goal is to remove the minimum number of intervals 
 * so that the remaining intervals do not overlap.
 *
 * Approach:
 * - Sort intervals by end time.
 * - Always keep the interval that ends earliest to maximize room for future ones.
 * - Count how many intervals overlap with the currently kept interval.
 *
 * Why not sort by start time?
 * - Sorting by start time doesn't guarantee the optimal solution.
 * - It might cause us to keep a long interval early on, which overlaps with many others.
 * - Sorting by end time ensures we always keep the interval that leaves the most room 
 *   for future non-overlapping intervals — a classic greedy choice.
 *
 * Time Complexity: O(n log n)
 *   - Sorting takes O(n log n)
 *   - One pass through the intervals: O(n)
 * 
 * Space Complexity: O(1)
 *   - Sorting is in-place, and only a few extra variables are used.
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ret = 0; // Count of intervals to remove

        // Sort intervals based on end time (greedy strategy)
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        // Initialize with the end time of the first interval
        int prev_end = intervals[0][1];

        // Iterate over remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval starts before the previous ends, it's overlapping
            if (intervals[i][0] < prev_end) {
                ret++; // Remove this interval (count it)
            } else {
                // No overlap, update the end to current interval's end
                prev_end = intervals[i][1];
            }
        }

        return ret; // Return the number of removed intervals
    }
};
