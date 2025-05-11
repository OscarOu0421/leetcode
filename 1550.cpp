/*
 * Time Complexity: O(n)      // Traverse the array once
 * Space Complexity: O(1)     // Constant extra space
 */

class Solution {
public:
    // Function to check if there are three consecutive odd numbers in the array
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();     // Get the size of the array
        int cur = 0;            // Counter for current number of odd numbers in the window
        int size = 3;           // Window size to check for 3 consecutive odds

        // Two pointers for sliding window
        for (int l = 0, r = 0; r < n; r++) {
            if (arr[r] % 2)
                cur++;          // Increment count if current number is odd

            if (r - l + 1 == size && cur == size)
                return true;    // Found 3 consecutive odd numbers

            // Shrink the window if it reaches size 3
            while (r - l + 1 >= size) {
                if (arr[l] % 2)
                    cur--;      // Decrement count if the leftmost number is odd
                l++;            // Move left pointer forward
            }
        }
        return false; // No such sequence found
    }
};
