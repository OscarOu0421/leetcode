// Time Complexity: O(n log n)
//   - O(n) to count frequencies
//   - O(n log n) to push all elements into the priority queue
//   - O(k log n) to pop k elements (still ≤ O(n log n))
// Space Complexity: O(n)
//   - O(n) for the map and the priority queue

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;  // To store the frequency of each number
        priority_queue<pair<int, int>> pq;  // Max-heap storing {frequency, number}
        vector<int> ret;  // Result vector to store top k frequent elements

        for (auto num : nums) {
            map[num]++;  // Count the frequency of each number
        }

        for (auto [num, freq] : map) {
            pq.push({freq, num});  // Push {frequency, number} into the max-heap
        }
        
        for (int i = 0; i < k; i++) {
            auto [freq, num] = pq.top();  // Get the number with highest frequency
            pq.pop();                     // Remove it from the heap
            ret.push_back(num);           // Add it to the result
        }
        
        return ret;  // Return the top k frequent elements
    }
};
