// O(n) time, O(1) space
// traverse the list, keeping a track of current subarray, and compare to max
// considered growing sliding window and suoounding accumulator approach, but time complexity wasn't great
class Solution {
public:
    int maxSubArray(const std::vector<int> &nums) {
        for (const int num : nums) {
            current = std::max(num, current + num);
            max     = std::max(max, current);
        }

        return max;
    }
private:
    int current = 0;
    int max     = 0;
};
