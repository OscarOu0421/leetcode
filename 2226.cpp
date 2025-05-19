// Problem Summary:
// Given piles of candies (array), each pile can be split (not merged).
// Distribute candies to k children such that each child gets the same number of candies
// from a single pile (or subpile), maximize how many candies each child can get.

// Binary Search Insight:
// - We're searching for the maximum X such that we can split piles to serve at least k children,
//   where each child gets exactly X candies.
// - Predicate: Can we serve at least k children with X candies each?

// Time Complexity: O(n * log(max_candies))
//   - n = candies.size(), max_candies = max value in any pile (up to INT_MAX)
// Space Complexity: O(1)

class Solution {
public:
    // Check if it's possible to give each child 'piles' candies
    // by counting how many subpiles of size 'piles' can be made
    bool valid(vector<int>& candies, int piles, long long k) {
        for (auto c : candies) {
            k -= c / piles;           // reduce required count by subpiles from this pile
            if (k <= 0)               // early exit: enough subpiles formed
                return true;
        }
        return false;                 // not enough subpiles
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;                    // minimum possible candies per child
        int r = INT_MAX;             // exclusive upper bound for binary search

        // Binary search for the maximum X such that valid(X) is true
        while (l < r) {
            int m = l + (r - l) / 2;  // candidate number of candies per child
            if (valid(candies, m, k)) {
                l = m + 1;            // try to find a larger valid amount
            } else {
                r = m;                // try smaller values
            }
        }

        // Return l - 1 since l is the first invalid value
        // return l     → Used when searching for minimum X
        // return l - 1 → Used when searching for maximum X
        return l - 1;
    }
};
