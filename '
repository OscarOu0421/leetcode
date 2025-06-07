// Time Complexity: O(n log n), where n = length of string s
//   - Each character is pushed/popped from a priority_queue (heap), which takes O(log k) time
//   - Up to n characters, so total heap operations are O(n log n)
// Space Complexity: O(n)
//   - Stores up to n indices in priority_queues within the map

class Solution {
public:
    string clearStars(string s) {
        string ret;
        unordered_map<char, priority_queue<int>> map; // Map from char to max-heap of indices

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                // Replace '*' with a placeholder to exclude it later
                s[i] = '-';

                // Remove the most recent occurrence of the smallest lexicographical character
                for (char c = 'a'; c <= 'z'; c++) {
                    if (map.find(c) != map.end() && !map[c].empty()) {
                        int j = map[c].top(); // Most recent index of character 'c'
                        map[c].pop();         // Remove it from the heap
                        s[j] = '-';           // Mark it as deleted
                        break;                // Only remove one character per '*'
                    }
                }
                continue;
            }

            // Store the index of the current character for future reference
            map[s[i]].push(i);
        }

        // Build the result string excluding all marked characters
        for (auto c : s) {
            if (c != '-') {
                ret += c;
            }
        }

        return ret;
    }
};

