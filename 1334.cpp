// TC: O(n^3)
// SC: O(n^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        int cities = INT_MAX;
        int ret = 0;

        /*
         * find the shorest path between all pairs of node in weighted graph
         * Floyd Warshell Algorithm
         */
        for (auto e : edges) {
            dis[e[0]][e[1]] = e[2];
            dis[e[1]][e[0]] = e[2];
        }
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX)
                        continue;
                    dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dis[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= cities) {
                cities = count;
                ret = i;
            }
        }
        return ret;
    }
};
