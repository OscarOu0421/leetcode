// Time Complexity: O(n log n) — due to priority_queue insertions and deletions
// Space Complexity: O(n) — for storing elements in the priority_queue
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Use a min-heap (priority_queue with greater comparator) to sort the elements
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto num : nums)
            pq.push(num); // Insert each number into the heap (O(log n) per insert)

        int i = 0;
        while (!pq.empty()) {
            nums[i++] = pq.top(); // Extract elements in sorted order
            pq.pop(); // Remove the smallest element (O(log n))
        }
    }
};

