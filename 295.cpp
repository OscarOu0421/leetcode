// Time Complexity:
// - addNum: O(log n) for insertion and heap balancing
// - findMedian: O(1) since it accesses the tops of heaps
// Space Complexity: O(n) to store all elements
class MedianFinder {
public:
    // Max heap to store the smaller half of the numbers
    priority_queue<int> maxq;
    // Min heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> minq;
    int size = 0; // Total number of elements added

    // Constructor
    MedianFinder() {}

    void addNum(int num) {
        size++; // Increase total count

        // Always add to maxq first
        maxq.push(num);

        // Move the top of maxq to minq to balance size
        while (maxq.size() > (size / 2)) {
            int value = maxq.top();
            maxq.pop();
            minq.push(value);
        }

        // Ensure maxq's top <= minq's top to maintain ordering invariant
        while (!maxq.empty() && !minq.empty() && maxq.top() > minq.top()) {
            int value1 = maxq.top(); maxq.pop();
            int value2 = minq.top(); minq.pop();
            maxq.push(value2);
            minq.push(value1);
        }
    }

    double findMedian() {
        // If even number of elements, average the two middle elements
        if (maxq.size() == minq.size()) {
            return (double)(maxq.top() + minq.top()) / 2;
        }
        // Otherwise, the minq has one more element, and its top is the median
        return minq.top();
    }
};
