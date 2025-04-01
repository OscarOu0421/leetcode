class Solution {
public:
    /*
       Time Complexity: O(n) - We traverse the list once from right to left.
       Space Complexity: O(n) - We use a DP array of size n.
       
       Approach:
       - We use dynamic programming (bottom-up) to calculate the maximum points.
       - `dp[i]` represents the maximum points we can collect starting from question `i`.
       - We iterate from the last question to the first, storing the best possible score at each step.
    */
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0); // DP array to store max points from index i onward.

        /*
           DP Formula:
           dp[i] = max(questions[i][0] + (skip_index < n ? dp[skip_index] : 0), dp[i+1])
           - If we take the current question, add its points and skip `questions[i][1]` questions.
           - Otherwise, just take the maximum points from the next question.
        */
        
        for (int i = n - 1; i >= 0; i--) {
            int skip_index = i + questions[i][1] + 1; // Index of the next valid question after skipping

            // Option 1: Take the current question and add the points from the next valid question
            long long take = questions[i][0] + (skip_index < n ? dp[skip_index] : 0);
            
            // Option 2: Skip the current question and take the points from the next question
            long long skip = (i + 1 < n ? dp[i + 1] : 0);

            // Core line: Choose the optimal strategy at each step
            dp[i] = max(take, skip);
        }

        return dp[0]; // Maximum points we can earn starting from question 0
    }
};
