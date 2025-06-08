// This solution finds the node that is reachable from both node1 and node2
// such that the maximum distance from either node to this meeting node is minimized.
// It performs BFS from both nodes to compute distances to all other nodes.
// Time complexity: O(n), where n is the number of nodes.
// Space complexity: O(n), for distance arrays and visited sets.

class Solution {
public:
    // Performs BFS from node `u` to record shortest distance to each reachable node
    void bfs(vector<int> edges, int u, vector<int> &lengths) {
        int n = edges.size();
        queue<pair<int, int>> q;
        unordered_set<int> visited;

        q.push({u, 0});
        while (!q.empty()) {
            auto [u, len] = q.front();
            q.pop();

            visited.insert(u);
            lengths[u] = len;

            int v = edges[u];
            if (v >= 0 && visited.count(v) == 0) {
                q.push({v, len + 1});
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int minlen = INT_MAX;
        int ret = -1;

        vector<int> n1(n, -1);  // Distance from node1 to every other node
        vector<int> n2(n, -1);  // Distance from node2 to every other node

        // Perform BFS from both nodes to fill distance arrays
        bfs(edges, node1, n1);
        bfs(edges, node2, n2);

        // Find the node with the minimal max-distance from both node1 and node2
        for (int i = 0; i < n; i++) {
            if (n1[i] == -1 || n2[i] == -1)
                continue;  // Node not reachable from one of the sources

            int maxDist = max(n1[i], n2[i]);
            if (maxDist < minlen) {
                ret = i;
                minlen = maxDist;
            }
        }

        return ret;
    }
};

