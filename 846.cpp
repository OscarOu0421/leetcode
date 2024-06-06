// Time: O(nlogn), n is the size of the hand
// Space: O(m), m is the unique number size of the hand
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> map;
        int i = 0, cur = 0, next = 0, groupId = 0;

        // if the size of the array can not divided by groupSize.
        // just return false;
        if (hand.size() % groupSize)
            return false;
        
        sort(hand.begin(), hand.end());
        for (auto card : hand) {
            map[card]++;
        }

        // Start with minimum number of the array
        next = hand[0];
        while (i < hand.size()) {
            cur = next;
            next = -1;
            groupId = i / groupSize;
            while (i / groupSize == groupId) {
                // if the consecutive number is insufficient, return false;
                if (map[cur] == 0)
                    return false;
                // set the minimum number of next group
                if (--map[cur] && next < 0)
                    next = cur;
                cur++;
                i++;
            }
            // the current group and next group is not intersection,
            // then current index is the minimum number of next group.
            if (next < 0 && i < hand.size()) {
                next = hand[i];
            }
        }
        return true;
    }
};
