/*
 * Time Complexity: O(n), where n is the size of the `answers` vector.
 *   - We iterate over the vector once to count frequencies, and again over the map.
 *
 * Space Complexity: O(n), for the hash map storing counts of each answer.
 */

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> map; // count of each unique answer
        int ret = 0;

        // Count frequencies of each answer
        for (auto ans : answers) {
            map[ans]++;
        }

        // Calculate the minimum number of rabbits based on grouping
        for (auto [ans, freq] : map) {
            // Number of full groups needed for this answer
            int colors = ceil((double)freq / (ans + 1));
            // Each group contributes (ans + 1) rabbits
            ret += colors * (ans + 1);
        }
        return ret;
    }
};
