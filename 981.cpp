/**
 * Time Complexity (TC):
 * - set: O(1). 由於題目保證 timestamp 是嚴格遞增的，直接 push_back 即可維持有序。
 * - get: O(log N). 其中 N 是該 key 對應的 timestamp 數量。我們對 vector 進行二元搜尋。
 * * Space Complexity (SC):
 * - O(M * N). M 是 key 的數量，N 是平均每個 key 存儲的 value 數量。我們存儲了所有的輸入。
 */

class TimeMap {
public:
    // 使用 hash map 存儲：key -> [{時間1, 值1}, {時間2, 值2}, ...]
    // 這裡 vector 內的 pair 會依照 timestamp 自動保持由小到大排序
    unordered_map<string, vector<pair<int, string>>> map;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // 直接存入 vector 尾端
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // 1. 先確認 key 是否存在，避免不必要的記憶體配置
        if (map.find(key) == map.end())
            return "";
        
        auto &v = map[key];

        // 2. 二元搜尋：尋找第一個「大於」目標 timestamp 的位置 (upper_bound)
        // 傳入 make_pair(timestamp, "") 是為了讓搜尋目標與容器內元素型別 (pair) 一致
        auto it = upper_bound(v.begin(), v.end(), make_pair(timestamp, ""),
            [](const pair<int, string> &a, const pair<int, string> &b) {
                // 只比較 pair 的第一個元素：timestamp
                return a.first < b.first;
            });

        // 3. 處理搜尋結果：
        // 如果 it 指向開頭，表示所有儲存的時間都大於目標 timestamp，回傳空字串
        if (it == v.begin())
            return "";

        // 4. prev(it) 指向的是第一個「小於或等於」目標 timestamp 的位置
        // 例如：找 10，upper_bound 找到第一個 >10 的（可能是 12），那 prev(12) 就是 10 或比 10 小的最大值
        return prev(it)->second;
    }
};
