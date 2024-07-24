class Solution {
public:
    string removePairs(string s, string subs, int score, int &ret) {
        string newS = "";
        for (auto c : s) {
            if (newS.size() && newS.back() == subs[0] && c == subs[1]) {
                ret += score;
                newS.pop_back();
            } else {
                newS.push_back(c);
            }
        }
        return newS;
    }
    int maximumGain(string s, int x, int y) {
        int ret = 0;
        string find = x > y ? "ab" : "ba";
        int score = max(x, y);

        /*
         * Greedy
         * First choose the highest score to remvoe pair,
         * and get the "new" string after you remove the pair
         */
        string newS = removePairs(s, find, score, ret);
        /*
         * Second, choose the remain pair to removed
         */
        find = x < y ? "ab" : "ba";
        score = min(x, y);
        removePairs(newS, find, score, ret);
        return ret;
    }
};
