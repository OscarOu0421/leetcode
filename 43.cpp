// Time Complexity: O(m * n) - where m and n are the lengths of num1 and num2
// Space Complexity: O(m + n) - to store the result in a vector of size (m + n)
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(); // Length of num1
        int n = num2.size(); // Length of num2
        vector<int> num(m + n, 0); // Result array to store intermediate multiplication results
        string s = ""; // Final result string

        // If either number is "0", the result is "0"
        if (num1 == "0" || num2 == "0")
            return "0";
        
        // Multiply each digit of num1 and num2
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0'; // Convert character to integer
                int digit2 = num2[j] - '0'; // Convert character to integer
                num[i + j + 1] += digit1 * digit2; // Add product to the corresponding position
                num[i + j] += num[i + j + 1] / 10; // Carry over to the next higher position
                num[i + j + 1] %= 10; // Keep only the single digit at current position
            }
        }

        int i = 0;
        // Skip any leading zeros in the result
        while (i < m + n && num[i] == 0)
            i++;

        // Build the result string
        for (; i < m + n; i++) {
            s += to_string(num[i]);
        }
        return s; // Return the final result
    }
};
