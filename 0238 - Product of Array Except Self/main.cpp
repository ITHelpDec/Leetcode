// brute force attempt - looks like O(n^2), O(n) space, but takes too long
class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int> &nums) {
        std::vector<int> nums_copy;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            int result = std::accumulate(nums.begin(), it,         1, std::multiplies<int>()) *
                         std::accumulate(it + 1,       nums.end(), 1, std::multiplies<int>());
            nums_copy.emplace_back(result);
        }
        
        return nums_copy;
    }
};

// O(n) "paintbrush" approach, O(n) space
// a "brush" of accumulating products from left-to-right, then vice versa
class Solution2 {
public:
    std::vector<int> productExceptSelf(const std::vector<int> &nums) {
        int sz = nums.size();
        std::vector<int> results(sz, 1);

        // left-to-right
        int slider = 1;
        for (int i = 0; i != sz; ++i) {
            results[i] *= slider;
            slider     *= nums[i];
        }

        // right-to-left
        slider = 1;
        for (int i = sz - 1; i != -1; --i) {
            results[i] *= slider;
            slider     *= nums[i];
        }

        return results;
    }
};
