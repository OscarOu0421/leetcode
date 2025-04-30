// Time Complexity: O(n^2), where n is the number of points.
// Space Complexity: O(n)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ret = 0;               // Total cost of connecting all points
        int edges = 0;             // Number of edges added to MST
        vector<int> mst(n, false); // Track if a node is included in MST
        vector<int> dis(n, INT_MAX); // Minimum distance to MST for each node

        dis[0] = 0; // Start from point 0

        while (edges < n) {
            int mindis = INT_MAX;
            int u = 0;

            // Find the node not yet in MST with the smallest distance
            for (int i = 0; i < n; i++) {
                if (!mst[i] && dis[i] < mindis) {
                    mindis = dis[i];
                    u = i;
                }
            }

            edges++;         // Include this node in MST
            ret += mindis;   // Add its connection cost
            mst[u] = true;   // Mark node as included in MST

            // Update distances of remaining nodes to the MST
            for (int v = 0; v < n; v++) {
                if (!mst[v]) {
                    // Calculate Manhattan distance between u and v
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    dis[v] = min(dist, dis[v]); // Update if smaller
                }
            }
        }
        return ret; // Return total minimum cost to connect all points
    }
};
