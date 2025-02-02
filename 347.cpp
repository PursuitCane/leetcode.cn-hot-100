class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num]++;
        }

        auto minHeapCompare = [](pair<int, int> left, pair<int, int> right) {
		return left.second > right.second; // 自定义比较器，建立最小堆
};
std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(minHeapCompare)>
            heap(minHeapCompare);

        for (auto item : m) {
            if (heap.size() < k) {
                pair<int, int> p = make_pair(item.first, item. second);
                heap.push(p);
                continue;
            }
            if (item.second > heap.top().second) {
                heap.pop();
                pair<int, int> p = make_pair(item.first, item. second);
                heap.push(p);
            }

            
        }

        vector<int> ans;
        while (heap.empty() == false) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};
