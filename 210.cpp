// Time Complexity: O(V + E), where V = numCourses and E = number of prerequisites
// Space Complexity: O(V + E), for adjacency list and indegree array

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret; // Stores the topological order of courses
        vector<int> indegree(numCourses); // Number of prerequisites for each course
        vector<vector<int>> adjs(numCourses); // Adjacency list: course -> dependent courses
        queue<int> q; // Queue for processing courses with no prerequisites

        // Build graph and fill indegree array
        for (auto& p : prerequisites) {
            indegree[p[0]]++;               // Course p[0] has one more prerequisite
            adjs[p[1]].push_back(p[0]);     // Course p[1] is a prerequisite for p[0]
        }

        // Start with courses that have no prerequisites
        for (int course = 0; course < numCourses; course++) {
            if (indegree[course] == 0)
                q.push(course);
        }

        // Process courses in topological order
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ret.push_back(course); // Add to result as this course can now be taken

            // Decrease indegree of dependent courses
            for (int adj : adjs[course]) {
                if (--indegree[adj] == 0)   // If no prerequisites remain
                    q.push(adj);           // Add to queue
            }
        }

        // If we processed all courses, return the order
        return ret.size() == numCourses ? ret : vector<int>(); // Return empty if there's a cycle
    }
};
