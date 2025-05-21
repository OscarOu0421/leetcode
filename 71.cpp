/*
    Problem: Simplify Path (LeetCode)
    Approach: 
        - Split the input path by '/'.
        - Use a stack to track valid directory names.
        - Skip "." and pop for "..".
        - Reconstruct the path from the stack.

    Time Complexity: O(n), where n is the length of the input string.
    Space Complexity: O(n), for storing path components in the stack.
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> sk;
        string dir;
        
        // Parse the path and push valid directory components into the stack
        for (int i = 0; i < path.length(); ++i) {
            if (path[i] == '/') {
                if (!dir.empty()) {
                    sk.push(dir);
                    dir.clear();
                }
            } else {
                dir += path[i];
            }
        }

        // Push last component if not empty
        if (!dir.empty()) {
            sk.push(dir);
        }

        string ret;
        int deleted = 0;

        // Process stack from top to bottom, applying ".." and skipping "."
        while (!sk.empty()) {
            dir = sk.top();
            sk.pop();

            if (dir == ".") {
                continue;
            } else if (dir == "..") {
                deleted++;
            } else if (deleted > 0) {
                deleted--;
            } else {
                ret = '/' + dir + ret;
            }
        }

        return ret.empty() ? "/" : ret;
    }
};

