// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ret = 0;  // Tracks the total number of non-meeting days
        int cur = 1;  // Tracks the current day (starts from day 1)

        // Sort the meetings by their starting days to ensure correct order
        sort(meetings.begin(), meetings.end());

        // Iterate through each meeting interval
        for (auto& meeting : meetings) {
            int start = meeting[0];  // Start day of the meeting
            int end = meeting[1];    // End day of the meeting
            
            // If there’s a gap between the current day and the next meeting's start
            if (cur < start) {
                ret += start - cur;  // Add the gap as non-meeting days
            }

            // Move `cur` to the day after this meeting's end
            // Ensures `cur` doesn't move backward if meetings overlap
            cur = max(cur, end + 1);
        }

        // Add remaining non-meeting days if `cur` hasn't reached `days`
        if (cur <= days) {
            ret += days - cur + 1;
        }

        return ret;
    }
};
