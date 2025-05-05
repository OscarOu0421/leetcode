// Time Complexity: O(N log K), where N = number of points
// Space Complexity: O(K) for the max heap

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap to store {distance, point}
        priority_queue<pair<int, vector<int>>> maxq;
        vector<vector<int>> ret;

        for (auto point : points) {
            int x = point[0];
            int y = point[1];

            // calculate squared distance from origin
            int dis = x * x + y * y;

            // push the point with its distance into the heap
            maxq.push({dis, {x, y}});

            // if the heap exceeds k, remove the farthest point
            if (maxq.size() > k)
                maxq.pop();
        }

        // extract the k closest points from the heap
        while (!maxq.empty()) {
            auto pair = maxq.top();
            maxq.pop();
            ret.push_back(pair.second);
        }

        return ret;
    }
};
