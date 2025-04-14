// Time Complexity: O(n log n + log target)
// - O(n log n) to sort the coins
// - O(log target) for the while loop (each patch at least doubles `miss`)
// Space Complexity: O(1) extra space (excluding input)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());  // Sort coins to use the smallest denominations first

        long long miss = 1;  // The smallest value we can't form yet
        int i = 0;           // Pointer for iterating over coins
        int added = 0;       // Number of coins added to reach the goal

        while (miss <= target) {
            if (i < coins.size() && coins[i] <= miss) {
                // If the current coin value is <= miss, we can use it to build up to a higher value.
                // Since we can already make all values < miss, adding coins[i] allows us to
                // reach up to (miss - 1) + coins[i] => so we update miss accordingly.
                miss += coins[i++];
            } else {
                // If we can't use the current coin (too large), we need to patch the gap.
                // The greedy move is to add 'miss' itself as a new coin.
                // This doubles the range of values we can now form: [1, miss) becomes [1, 2*miss)
                // We do: miss += miss to reflect that.
                miss += miss;
                added++;
            }
        }

        return added;
    }
};
