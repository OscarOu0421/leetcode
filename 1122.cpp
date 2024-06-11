// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int idx = 0;
        unordered_map<int, int> map;
        vector<int> remain;

        for (auto num : arr1) {
            map[num]++;
        }

        for (auto num : arr2) {
            while (map[num]) {
                arr1[idx++] = num;
                map[num]--;
            }
        }

        for (auto it : map) {
            while (it.second--) {
                remain.push_back(it.first);
            }
        }

        sort(remain.begin(), remain.end());
        for (auto num : remain) {
            arr1[idx++] = num;
        }

        return arr1;
    }
};
