// O(n) solution
// loop through the list of numbers and add tehm to a frequency map
// flip the keys and values and put them into a priority_queue that will naturally sort the largest value to the top
// decrement through k and add each highest value to your answer

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::vector<int> answer;

        for (int num : nums) { ++occurences_[num]; }

        std::priority_queue<std::pair<int, int>> min_heap;

        for (const auto [num, occurence] : occurences_) { min_heap.push({ occurence, num }); }

        while (k--) {
            answer.emplace_back(min_heap.top().second);
            min_heap.pop();
        }

        return answer;
    }
private:
    std::unordered_map<int, int> occurences_;
};
