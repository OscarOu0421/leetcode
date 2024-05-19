// Time: O(8n), n is the bank size
// Space: O(2n)
class Solution {
public:
    void mutation(queue<string> &queue, unordered_set<string> &set, string &str, int i, char c) {
        str[i] = c;
        if (set.count(str))
            queue.push(str);
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> set;
        queue<string> queue;
        int ret = 0;

        for (auto str : bank) {
            set.insert(str);
        }
        
        if (set.count(endGene) == 0)
            return -1;

        queue.push(startGene);
        while (!queue.empty()) {
            int s = queue.size();
            while (s-- > 0) {
                string str = queue.front();
                queue.pop();
                // We reach the end Gene
                if (str == endGene)
                    return ret;
                // If we check this string is not the end Gene,
                // then we erase this string to void redundant checking
                set.erase(str);
                // As the length of the string is 8, and it can take A, C, G, T
                // we iterate each character to check the posibility of mutation by
                // replacaing with A, C, G, T
                for (int i = 0; i < 8; i++) {
                    string tmp = str;
                    mutation(queue, set, tmp, i, 'A');
                    mutation(queue, set, tmp, i, 'C');
                    mutation(queue, set, tmp, i, 'G');
                    mutation(queue, set, tmp, i, 'T');
                }
            }
            ret++;
        }
        return -1;
    }
};
