/*
 Time Complexity (TC):
 - O(log10(n))
   n = absolute value of x
   Each iteration removes one digit from x.

 Space Complexity (SC):
 - O(1)
   Only constant extra space is used (ret, digit, etc.).
*/
class Solution {
public:
    int reverse(int x) {
        long long ret = 0;  // Use long long to avoid intermediate overflow
        int digit = 0;      // Current digit extracted from x

        while (x != 0) {
            digit = x % 10;          // Extract last digit
            ret = ret * 10 + digit;  // Append digit to the reversed number

            // Check for overflow in 32-bit int range
            if (ret > INT_MAX || ret < INT_MIN)
                return 0;

            x /= 10;                  // Remove last digit from x
        }

        return (int)ret;  // Safe to cast because we checked overflow
    }
};

