/*
 * Time: O(nlogn + klogn), n is the number of projects, k is the number of projects
 * we can select.
 * O(nlogn): sorting the projects vector and the for loop adds the available
 * projects to the priority queue at most n times.
 * O(klogn) : removeing projects from the priority queue at most k times.
 *
 * Space: O(n+n) used to projects vector and the priority queue.
 */
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), i;
        vector<pair<int, int>> projects(n);
        priority_queue<int> maxCapital;

        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        /*
         * We sort the projects by the min capital required in ascending order.
         * Because we want to consider the projects that we can afford with 
         * our current capital.
         * By iterating over the sorted projects, we can ensure that we only 
         * consider the projects that have min capital requirement less than or 
         * equal to our current capital.
         */
        sort(projects.begin(), projects.end());
        
        i = 0;
        while (k--) {
            /*
             * We can add the project to the priority queue based on our current 
             * capital.
             */
            for (; i < n && projects[i].first <= w; i++) {
                maxCapital.push(projects[i].second);
            }
            if (maxCapital.empty())
                break;
            w += maxCapital.top();
            maxCapital.pop();
        }
        return w;
    }
};
