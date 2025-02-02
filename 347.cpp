class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }

        auto maxHeapCompare = [](pair<int, int> left, pair<int, int> right) {
		return left.second < right.second; // 自定义比较器，建立最大堆
};
std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(maxHeapCompare)>
            heap(maxHeapCompare);

        for (auto item : m) {
            pair<int, int> p = make_pair(item.first, item. second);
            heap.push(p);
        }

        vector<int> ans;
        while (k--) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};
