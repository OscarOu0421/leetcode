// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ret(2, 0);
        double l = 0, r = 1, mid;
        
        while (l <= r) {
            mid = (l + r ) / 2;
            int i = 0, j = 1, total = 0, a, b;
            double max = 0;
            for (; i < n; i++) {
                while (j < n && arr[i] >= arr[j] * mid)
                    j++;
                
                total += n - j;
                if (j < n && max < arr[i] * 1.0 /arr[j]) {
                    a = arr[i];
                    b = arr[j];
                    max = arr[i] * 1.0 / arr[j];
                }
            }
            if (total == k) {
                ret[0] = a;
                ret[1] = b;
                break;
            } else if (total > k)
                r = mid;
            else 
                l = mid;
        }
        return ret;
    }
};
