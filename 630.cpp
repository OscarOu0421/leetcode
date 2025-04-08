// Time Complexity: O(n log n)
//   - O(n log n) for sorting courses by lastDay
//   - O(n log n) for heap operations across all courses
// Space Complexity: O(n) for the max heap (worst case: all courses taken)

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq; // Max heap to store durations of selected courses
        int cur = 0; // Current total time used

        // Sort courses by their lastDay (deadline)
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        for (auto& course : courses) {
            int duration = course[0];
            int lastday = course[1];

            pq.push(duration);  // Assume we take this course
            cur += duration;    // Add its duration to the current time

            // If current time exceeds the course's deadline,
            // drop the longest duration course taken so far
            while (!pq.empty() && cur > lastday) {
                cur -= pq.top(); // Remove the longest duration
                pq.pop();
            }
        }

        // The number of courses successfully taken
        return pq.size();
    }
};
