/*
    Problem: Evaluate Division (LeetCode)
    Approach: Build a bidirectional weighted graph from the equations and use DFS to evaluate queries.

    Time Complexity:
        - Building the graph: O(E), where E is the number of equations
        - For each query, worst-case DFS traversal: O(N + E), where
            N = number of variables (nodes)
            E = number of relationships (edges)
        - Total complexity: O(Q * (N + E)), where Q is the number of queries

    Space Complexity:
        - Graph (adjacency list): O(E)
        - DFS stack and visited set: O(N) per query
        - Total: O(N + E)
*/

class Solution {
public:
    // Helper function to perform DFS to find the result of a query
    double dfs(unordered_map<string, vector<pair<string, double>>> &adjs, vector<string> querie) {
        string src = querie[0];
        string dst = querie[1];
        stack<pair<string, double>> sk;
        unordered_set<string> visited;

        // Return -1.0 if either source or destination is not in the graph
        if (adjs[src].size() == 0 || adjs[dst].size() == 0)
            return -1.0;

        // Start DFS with source node and an initial product value of 1.0
        sk.push({src, 1.0});
        while (!sk.empty()) {
            auto [u, value] = sk.top();
            sk.pop();

            // If we reach the destination, return the accumulated product
            if (u == dst)
                return value;

            visited.insert(u);

            // Visit all unvisited neighbors and update the accumulated product
            for (auto [v, w] : adjs[u]) {
                if (visited.count(v) == 0)
                    sk.push({v, w * value});
            }
        }

        // If no path was found, return -1.0
        return -1.0;
    }

    // Main function to evaluate all queries
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adjs;
        vector<double> ret;

        // Build the graph with both directions (u/v and v/u)
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            adjs[u].emplace_back(v, w);
            adjs[v].emplace_back(u, 1 / w);
        }

        // Evaluate each query using DFS
        for (auto querie : queries) {
            ret.push_back(dfs(adjs, querie));
        }

        return ret;
    }
};
