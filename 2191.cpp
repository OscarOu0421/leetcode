// TC: O(nlogn)
// SC: O(n)
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, queue<int>> map;
        vector<int> ret(n);

        /*
         * map: key = mapping value, value = original value queue with the same mapping value
         * use queue could maintain the same order for those same mapping value
         */
        for (int i = 0; i < n; i++) {
            int newNum = 0, l = 1, num = nums[i];
            if (num == 0) {
                newNum = mapping[0];
            }
            while (num) {
                newNum += mapping[num % 10] * l;
                num /= 10;
                l *= 10;
            }
            ret[i] = newNum;
            map[newNum].push(nums[i]);
        }
        sort(ret.begin(), ret.end());
        
        for (int i = 0; i < n;) {
            queue<int> q = map[ret[i]];
            while (!q.empty()) {
                ret[i++] = q.front();
                q.pop();
            }
        }
        return ret;
    }
};
