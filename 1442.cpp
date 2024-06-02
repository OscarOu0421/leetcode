// Time: O(n^2)
// Space: O(1)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ret = 0;

        /* 
         * Create prefix xor array, size of array becomes to n+1
         * prefix[i] = arr[0] ^ arr[1] ^ ... ^ arr[i-1]
         */
        arr.insert(arr.begin(), 0);
        n++;
        for (int i = 1; i < n; i++) {
            arr[i] ^= arr[i-1];
        }
        
        /*
         * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
         * b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
         * a == b 
         * implies 0 = a ^ b
         * implies 0 = arr[i] ^ arr[i + 1] ^ ... ^ arr[k]
         * implies prefix[i] == prefix[k+1]
         * where prefix[i] = arr[0] ^ arr[1] ^ ... ^ arr[i-1]
         * prefix[k+1] = arr[0] ^ arr[1] ^ ... ^ arr[k].
         * if i < j <= k for original index, we should modify to i < j < k+1,
         * then the options for j is (k+1) - i - 1.
         */
        for (int i = 0; i < n; i++) {
            for (int k = i+1; k < n; k++) {
                // arr[k] is prefix[k+1]
                if (arr[i] == arr[k]) {
                    ret += k - i - 1;
                }
            }
        }
        return ret;
    }
};
