// Time Complexity: O(n * log n), where log n is for digit summing.
// Space Complexity: O(n), in the worst case we may have up to n different digit sums.
class Solution {
public:
    // Helper function to compute the sum of digits of a number
    int digits(int n) {
        int ret = 0;
        while (n) {
            ret += n % 10; // Add the last digit
            n /= 10;       // Remove the last digit
        }
        return ret; // Return the total sum of digits
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> map; // Map to count occurrences of each digit sum
        int maxSize = 0;             // Track the size of the largest group
        int ret = 0;                 // Track the number of groups with size == maxSize

        for (int i = 1; i <= n; i++) {
            int digit = digits(i);   // Get the sum of digits of the number
            map[digit]++;            // Increment the count of this digit sum

            if (map[digit] > maxSize) {
                maxSize = map[digit]; // Found a new larger group
                ret = 1;              // Reset count to 1 for this new group size
            } else if (map[digit] == maxSize) {
                ret++;                // Another group with the same max size
            }
        }

        return ret; // Return the number of groups that have the largest size
    }
};
