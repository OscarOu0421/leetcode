// Time Complexity: O(N * α(N)) ~ practically O(N), where α is inverse Ackermann function (very slow-growing)
// Space Complexity: O(N) for the parent array

class Solution {
public:
    vector<int> parent;  // parent[i] stores the parent of node i

    // Find the root parent of x with path compression
    int find(int x) {
        if (x != parent[x]) {              // If x is not the root
            parent[x] = find(parent[x]);   // Path compression
        }
        return parent[x];                  // Return root
    }

    // Union the sets of x and y; return false if they are already connected (cycle)
    bool unionset(int x, int y) {
        int px = find(x);                  // Find root of x
        int py = find(y);                  // Find root of y
        if (px == py)                      // If roots are the same, cycle detected
            return false;
        parent[py] = px;                   // Union: make px the parent of py
        return true;
    }

    // Main function to find the redundant edge
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();              // Number of edges
        parent.resize(n + 1, 0);           // Resize parent array to hold n nodes

        for (int i = 1; i <= n; i++) {
            parent[i] = i;                 // Initialize each node as its own parent
        }

        for (auto edge : edges) {          // Iterate over each edge
            int u = edge[0];
            int v = edge[1];

            if (!unionset(u, v))           // If union fails, cycle found
                return edge;               // Return the redundant edge
        }

        return {};                         // Should not reach here for valid input
    }
};
