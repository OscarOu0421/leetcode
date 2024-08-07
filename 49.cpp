// TC: O(n*mlogm), m is avg size of string
// SC: O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> ret;

        for (auto str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            if (map.find(key) == map.end()) {
                map[key] = ret.size();
                ret.push_back(vector<string>());
            }
            ret[map[key]].push_back(str);
        }
        return ret;
    }
};
