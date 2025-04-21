// Time Complexity: O(n) — one pass through the differences vector
// Space Complexity: O(1) — only constant extra space used

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long cur = 0;            // Running sum of the sequence
        long long minValue = 0;       // Minimum value in the running sum
        long long maxValue = 0;       // Maximum value in the running sum

        // Compute prefix sums and track the min and max values
        for (int diff : differences) {
            cur += diff;
            minValue = min(minValue, cur);
            maxValue = max(maxValue, cur);
        }

        // Adjust maxValue based on lower bound of the valid range
        if (minValue < lower) {
            maxValue += abs(lower - minValue);
        } else {
            maxValue -= abs(minValue - lower);
        }

        // Set minValue to lower as the adjusted start
        minValue = lower;

        // Count how many valid starting values x exist such that
        // x + prefix stays in [lower, upper]
        return max(0LL, upper - maxValue + 1);
    }
};
