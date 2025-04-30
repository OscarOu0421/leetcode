class Solution {
public:
    int evendigit (int num) {
        int digit = 0;

        while (num) {
            num /= 10;
            digit++;
        }
        return digit % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for (auto num : nums)
            if (evendigit(num))
                ret++;
        return ret;
    }
};
