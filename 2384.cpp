// Time: O(n)
// Space: O(1)
class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> nums(10, 0);
        string left, right, single;

        // Record the frequency of each digit.
        for (char c : num) {
            nums[c - '0']++;
        }

        // Start with the digit '9' to create largest number
        for (int i = 9; i >= 0 ; i--) {
            while (nums[i] >= 2) {
                // if the left and right string is empty and we add zero dto it.
                // it will have leading zero.
                if (i == 0 && left == "" && right == "")
                    break;
                left += to_string(i);
                right += to_string(i);
                nums[i] -= 2;
            }
            // we can add one digit at the middle of palindrome number.
            if (nums[i] && single == "") {
                single = to_string(i);
            }
        }
        reverse(right.begin(), right.end());
        return left + single + right;
    }
};
