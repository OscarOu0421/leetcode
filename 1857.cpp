// Time Complexity: O(n + e + 26n) = O(n + e), where n = number of nodes, e = number of edges
// Space Complexity: O(n + e + 26n) = O(n + e)
// Explanation: We process each node and edge once in topological sort, and we maintain a 26-sized color count for each node.

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();  // number of nodes
        int visited = 0;        // counter to track number of visited nodes
        int ret = 0;            // result: max color value along any valid path
        queue<int> q;           // queue for topological sort
        vector<int> indegree(n, 0);  // indegree count for each node
        vector<vector<int>> record(n, vector<int>(26, 0)); // record[node][color] = max count of color on path to node
        unordered_map<int, vector<int>> adjs;  // adjacency list

        // Build graph and fill indegree
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indegree[v]++;
            adjs[u].push_back(v);
        }

        // Initialize queue with nodes having zero indegree (starting points)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        // Topological sort using Kahn’s algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            int color = colors[node] - 'a';  // map color to index 0-25
            visited++;  // count this node as visited
            record[node][color]++;  // increment count of this node's color
            ret = max(ret, record[node][color]);  // update result if needed

            for (auto adj : adjs[node]) {
                indegree[adj]--;  // reduce indegree as current node is removed
                if (indegree[adj] == 0)
                    q.push(adj);  // push to queue if no more dependencies

                // propagate the color counts to the adjacent node
                for (int i = 0; i < 26; i++) {
                    record[adj][i] = max(record[adj][i], record[node][i]);
                }
            }
        }

        // If all nodes were visited, return the max color count; otherwise, cycle exists
        return visited == n ? ret : -1;
    }
};
