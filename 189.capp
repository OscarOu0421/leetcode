// Time : O(n)
// Space: O(1)

class Solution {
public:
    void reverse(vector<int> &nums, int start, int end) {
        int l = start, r = end, tmp;

        while (l < r) {
            tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // input: 1 2 3 4 5 6 7
        // k = 3
        
        k = k % n;

        // 7 6 5 4 3 2 1
        reverse(nums, 0, n-1);
        // 5 6 7 4 3 2 1
        reverse(nums, 0, k-1);
        // 5 6 7 1 2 3 4
        reverse(nums, k, n-1);
    }
};
