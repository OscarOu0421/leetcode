/**
 * Time Complexity (TC):
 * - add: O(1) 
 * - count: O(U) where U is the number of UNIQUE points added to the system.
 * * Space Complexity (SC): O(N)
 * We store counts for all points in a nested hash map and unique pairs in a vector.
 */

class DetectSquares {
public:
    // Nested map to store frequency: x -> {y -> count}
    unordered_map<int, unordered_map<int, int>> m;
    // Vector of unique points to iterate through during count()
    vector<pair<int, int>> p;

    DetectSquares() {}
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        // If this specific coordinate hasn't been seen before, track it as a unique point
        if (m[x][y] == 0) {
            p.push_back({x, y});
        }
        m[x][y]++; // Increment the count for this point
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int ret = 0;

        // Iterate through all unique points (x2, y2) to see if they can form a diagonal
        for (auto [x2, y2] : p) {
            // A square is formed if:
            // 1. The absolute distance in X equals the absolute distance in Y (square property)
            // 2. The distance is non-zero (cannot use the query point itself)
            if (abs(x1 - x2) == 0 || abs(x1 - x2) != abs(y1 - y2))
                continue;

            // If (x1,y1) and (x2,y2) are diagonal corners, the other two corners must be:
            // Corner 3: (x1, y2)
            // Corner 4: (x2, y1)
            // The total number of squares is the product of the counts of the three other corners.
            if (m.count(x1) && m[x1].count(y2) && m.count(x2) && m[x2].count(y1)) {
                ret += m[x1][y2] * m[x2][y1] * m[x2][y2];
            }
        }
        return ret;
    }
};
