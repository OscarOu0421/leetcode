// Time: O(2^n), 2^n subset
// Space: O(n), most n words in the step
class Solution {
public:
    bool canTakeWord(string word, unordered_map<char, int> freq) {
        for (auto c : word) {
            if (freq[c] == 0)
                return false;
            freq[c]--;
        }
        return true;
    }
    void adjustWord(string word, unordered_map<char, int> &freq, int adjust) {
        for (auto c : word) {
            cout << c << endl;
            freq[c] += adjust;
        }
    }
    int toScore(vector<string> &step, vector<int> &score) {
        int ret = 0;
        for (auto word : step) {
            for (auto c : word) {
                ret += score[c - 'a'];
            }
        }
        return ret;
    }
    void dfs(vector<string> &words, unordered_map<char, int> &freq, vector<int> &score, vector<string> &step, int i, int &ret) {
        // End of the words, check the total scores of the step.
        if (i == words.size()) {
            ret = max(toScore(step, score), ret);
            return;
        }

        // Not take the words[i]
        dfs(words, freq, score, step, i+1, ret);
        // Take the words[i]
        if (canTakeWord(words[i], freq)) {
            // Choose
            adjustWord(words[i], freq, -1);
            step.push_back(words[i]);
            // Explore
            dfs(words, freq, score, step, i+1, ret);
            // Unchoose
            adjustWord(words[i], freq, 1);
            step.pop_back();
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> freq;
        vector<string> step;
        int ret = 0;

        for (char c : letters) {
            freq[c]++;
        }
        dfs(words, freq, score, step, 0, ret);
        return ret;
    }
};
