class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int i = 0, cur = 0, next = 0, groupId = 0;

        // if the size of the array can not divided by groupSize.
        // just return false;
        if (nums.size() % k)
            return false;
        
        sort(nums.begin(), nums.end());
        for (auto card : nums) {
            map[card]++;
        }

        // Start with minimum number of the array
        next = nums[0];
        while (i < nums.size()) {
            cur = next;
            next = -1;
            groupId = i / k;
            while (i / k == groupId) {
                // if the consecutive number is insufficient, return false;
                if (map[cur] == 0)
                    return false;
                // set the minimum number of next group
                if (--map[cur] && next < 0)
                    next = cur;
                cur++;
                i++;
            }
            // the current group and next group is not intersection,
            // then current index is the minimum number of next group.
            if (next < 0 && i < nums.size()) {
                next = nums[i];
            }
        }
        return true;
    }
};
