// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        int num = 0;

        for (int i = n-1; i >= 0; i--) {
            if (i == n-1)
                digits[i]++;
            num = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = num;
            if (!carry)
                break;
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
