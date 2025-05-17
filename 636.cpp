// Time Complexity: O(m), where m = logs.size()
//   - Each log is processed once, with constant-time stack operations and parsing
// Space Complexity: O(n + m)
//   - O(n) for the result vector, O(m) for the stack in the worst case (all starts before any ends)

class Solution {
public:
    // Parses a log string of the format "id:op:time" into a tuple (id, op, time)
    tuple<int, string, int> parse(const string& s) {
        size_t pos1 = s.find(':');                      // Find first ':' to extract id
        size_t pos2 = s.find(':', pos1 + 1);            // Find second ':' to extract operation
        int id = stoi(s.substr(0, pos1));               // Convert id substring to int
        string op = s.substr(pos1 + 1, pos2 - pos1 - 1); // Extract operation ("start" or "end")
        int time = stoi(s.substr(pos2 + 1));            // Convert time substring to int
        return {id, op, time};
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<tuple<int, string, int>> stk;             // Stack to keep track of active functions
        vector<int> result(n, 0);                       // Stores exclusive execution times per function

        for (const string& log : logs) {
            auto [id, op, time] = parse(log);           // Parse the current log entry

            if (op == "start") {
                stk.push({id, op, time});               // Push function start info onto the stack
            } else {
                auto [start_id, _, start_time] = stk.top(); // Get the function at the top of the stack
                stk.pop();                              // Remove the function since it's ending
                int duration = time - start_time + 1;   // Compute inclusive execution time
                result[start_id] += duration;           // Add time to current function's total

                if (!stk.empty()) {
                    auto [parent_id, __, ___] = stk.top(); // If nested, subtract time from parent
                    result[parent_id] -= duration;
                }
            }
        }
        return result;
    }
};

