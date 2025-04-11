// Time Complexity: O(N * D), where N = high - low + 1, D is the number of digits in the number (up to 6 for range up to 999999)
// Space Complexity: O(D) per iteration due to string conversion (negligible constant space)

// This solution counts numbers between low and high that have even number of digits
// and the sum of the first half of digits equals the sum of the second half.

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;  // Initialize the count of symmetric integers

        for (int num = low; num <= high; num++) {  // Iterate over the range [low, high]
            string s = to_string(num);             // Convert the number to a string
            int len = s.size();                    // Get the number of digits
            int left = 0;                          // Sum of the first half of digits
            int right = 0;                         // Sum of the second half of digits

            if (len % 2)                           // Skip numbers with an odd number of digits
                continue;

            for (int i = 0; i < len / 2; i++)      // Calculate sum of the left half
                left += s[i] - '0';
            for (int i = len / 2; i < len; i++)    // Calculate sum of the right half
                right += s[i] - '0';

            if (left == right)                     // If symmetric, increment count
                ret++;
        }
        return ret;                                // Return the final count
    }
};
