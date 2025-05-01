// Time Complexity: O(E * log V), where E = number of edges, V = number of nodes
// Space Complexity: O(V + E) for graph and priority queue

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph; // Adjacency list: u -> {v, weight}
        vector<int> timeList(n + 1, INT_MAX);             // Time to reach each node (1-based index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minq; // Min-heap: {time, node}
        int ret = 0; // Maximum time to reach any node

        timeList[0] = 0; // node 0 is unused, so set to 0 to ignore later

        // Build the graph
        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
        }

        // Start with source node k
        minq.push({0, k});

        // Dijkstra's algorithm
        while (!minq.empty()) {
            auto [time, u] = minq.top();
            minq.pop();

            // Skip if we already found a shorter path to u
            if (timeList[u] < time)
                continue;

            // Update the shortest time to reach u
            timeList[u] = time;

            // Check all neighbors
            for (auto [v, w] : graph[u]) {
                if (timeList[v] > time + w) {
                    minq.push({time + w, v}); // Relax the edge and push to queue
                }
            }
        }

        // Find the maximum time from the source to any node
        for (auto time : timeList) {
            ret = max(ret, time);
        }

        // If any node is unreachable, return -1
        return ret == INT_MAX ? -1 : ret;
    }
};
