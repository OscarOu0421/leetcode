// TC:O(n)
// SC:O(1)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        int n = s.size();
        int ret = 0;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        for (int i = 0; i < n-1; i++) {
            if (map[s[i]] < map[s[i+1]])
                ret -= map[s[i]];
            else
                ret += map[s[i]];
        }
        ret += map[s[n-1]];
        return ret;
    }
};
