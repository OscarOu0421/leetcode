// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26] = {0};
        int i = 0;
        
        for (auto c : magazine) {
            map[c-'a']++;
        }
        for (auto c : ransomNote) {
            if (map[c-'a'] == 0) {
                return false;
            }
            map[c-'a']--;
        }
        return true;
    }
};
