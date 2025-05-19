// Problem Summary:
// Given bloomDay array, m bouquets to make, and k adjacent flowers per bouquet,
// return the minimum number of days needed to make m bouquets, or -1 if impossible.

// Binary Search Insight:
// - You're asked to find the *minimum* day D such that a condition is true.
// - The condition: Can we make m bouquets by day D?
// - This is a classic binary search pattern: search for the smallest D such that predicate(D) is true.
// - The predicate (helper) is monotonic: once you can make m bouquets, you'll always be able to with more days.

// Time Complexity: O(n * log(max_day))
// Space Complexity: O(1)

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1;                // earliest possible day
        int r = INT_MAX;          // latest possible day
        unsigned long long total = (unsigned long long)m * k; // total flowers needed

        // If not enough flowers in total, return -1 early
        if (bloomDay.size() < total)
            return -1;

        // Binary search to find the smallest day that allows m bouquets
        while (l < r) {
            int mid = l + (r - l) / 2; // Candidate day to check
            int bouquet = 0;           // Bouquets formed
            int flower = 0;            // Consecutive bloomed flowers

            // Check if we can make m bouquets by day `mid`
            for (auto day : bloomDay) {
                if (day > mid) {
                    flower = 0;        // Reset streak if flower not bloomed
                } else {
                    if (++flower == k) { // Found k consecutive bloomed flowers
                        bouquet++;
                        flower = 0;    // Reset for next bouquet
                    }
                }
            }

            // If enough bouquets, try smaller day
            if (bouquet >= m)
                r = mid;
            else
                l = mid + 1; // Otherwise, we need more days
        }

        return l; // Minimum day needed to make m bouquets
    }
};
