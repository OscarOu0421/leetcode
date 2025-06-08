/*
Time Complexity:
Let n = number of nodes in edges1 (n = edges1.size() + 1)
    m = number of nodes in edges2 (m = edges2.size() + 1)
    k = maximum BFS depth

- buildadj runs in O(n + m) for both trees.
- bfs is called m times on edges2, each up to O(m) nodes → O(m²) in worst case.
- bfs is called n times on edges1, each up to O(n) nodes → O(n²) in worst case.

=> Total Time Complexity: O(n² + m²)
   (In sparse trees and small k: O(n * d^k + m * d^(k-1)), where d ≈ 2)

Space Complexity:
- Adjacency lists: O(n + m)
- Return vector: O(n)
- Temporary structures in bfs (visited, queue): O(n) or O(m) per call, reused.

=> Total Space Complexity: O(n + m)
*/

class Solution {
public:
    // Helper function to build an adjacency list from edge list
    void buildadj(vector<vector<int>>& edges, unordered_map<int, vector<int>> &adj) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Because the graph is undirected
        }
    }

    // Perform BFS to count number of nodes reachable within distance k from given node
    int bfs(unordered_map<int, vector<int>> &adjs, int k, int node) {
        unordered_set<int> visited;               // To track visited nodes
        queue<pair<int, int>> q;                  // Pair of (current node, current distance)
        int targets = 0;                          // Count of reachable target nodes

        q.push({node, 0});
        while (!q.empty()) {
            auto [u, len] = q.front();
            q.pop();

            visited.insert(u);                    // Mark node as visited
            if (len > k) continue;                // Skip nodes beyond depth k

            targets++;                            // Count this node

            for (auto v : adjs[u]) {              // Traverse neighbors
                if (visited.count(v) == 0) {
                    q.push({v, len + 1});
                }
            }
        }
        return targets;
    }

    // Main function to compute the max reachable target nodes
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int m = edges2.size() + 1;                        // Number of nodes in tree 2
        int n = edges1.size() + 1;                        // Number of nodes in tree 1
        int second = 0;                                   // Max targets from second tree
        unordered_map<int, vector<int>> adj1, adj2;       // Adjacency lists
        vector<int> ret(n, 0);                            // Result for each node in tree 1

        buildadj(edges1, adj1);                           // Build adjacency list for tree 1
        buildadj(edges2, adj2);                           // Build adjacency list for tree 2

        // Find the max number of targets reachable from any node in tree 2 within (k-1) distance
        for (int i = 0; i < m; i++) {
            second = max(second, bfs(adj2, k - 1, i));
        }

        // For each node in tree 1, find reachable targets within distance k and add best from tree 2
        for (int i = 0; i < n; i++) {
            ret[i] = bfs(adj1, k, i) + second;
        }

        return ret;
    }
};

