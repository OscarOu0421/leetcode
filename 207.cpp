// Time Complexity: O(V + E), where V = numCourses and E = number of prerequisites
// Space Complexity: O(V + E), for the adjacency list and indegree array

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjs(numCourses, vector<int>()); // Adjacency list: course -> list of dependent courses
        vector<int> indegree(numCourses, 0); // Number of prerequisites for each course
        queue<int> q; // Queue for courses with no remaining prerequisites
        int finished = 0; // Count of courses we can take

        // Build graph and indegree array
        for (auto p : prerequisites) {
            indegree[p[0]]++;               // Course p[0] has one more prerequisite
            adjs[p[1]].push_back(p[0]);     // Course p[1] is a prerequisite for p[0]
        }

        // Initialize queue with courses having no prerequisites
        for (int course = 0; course < numCourses; course++) {
            if (indegree[course] == 0)
                q.push(course);
        }

        // Process courses in topological order
        while (!q.empty()) {
            int course = q.front(); // Take a course with no prerequisites
            q.pop();
            finished++; // One more course completed

            // Reduce indegree of dependent courses
            for (auto adj : adjs[course]) {
                if (--indegree[adj] == 0) { // If a dependent course has no remaining prerequisites
                    q.push(adj);           // It can now be taken
                }
            }
        }

        // If we finished all courses, return true
        return finished == numCourses;
    }
};
