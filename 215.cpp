// Time Complexity: O(n log k)
//   - O(log k) per insertion/removal in the heap
// Space Complexity: O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to keep track of top k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);            // Insert current number
            if (pq.size() > k) {     // Maintain size k
                pq.pop();            // Remove the smallest
            }
        }

        return pq.top(); // The k-th largest element
    }
};
