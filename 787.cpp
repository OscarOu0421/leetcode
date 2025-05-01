// Time Complexity: O(E * K), where E is the number of flights and K is the max number of stops
// Space Complexity: O(N * K) for the prices table, and O(E + N*K) for the graph and priority queue

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph; // adjacency list: node -> list of (neighbor, cost)
        vector<vector<int>> prices(n, vector<int>(k + 2, INT_MAX)); // prices[i][s] = min cost to reach node i with s stops
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minq; // min-heap: (price, node, stops)

        // Build the graph
        for (auto edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
        }

        // Start from src with cost 0 and 0 stops
        minq.push({0, src, 0});
        prices[src][0] = 0;

        // Dijkstra-like traversal with stop tracking
        while (!minq.empty()) {
            auto [price, u, stop] = minq.top();
            minq.pop();

            // If destination reached, return the cost
            if (u == dst)
                return price;

            // If we've used more than k stops, skip
            if (stop > k)
                continue;

            // Explore all neighbors
            for (auto [v, w] : graph[u]) {
                int newCost = price + w;
                // Only proceed if we find a cheaper price with stop+1
                if (newCost < prices[v][stop + 1]) {
                    prices[v][stop + 1] = newCost;
                    minq.push({newCost, v, stop + 1});
                }
            }
        }

        // If destination cannot be reached within k stops
        return -1;
    }
};
