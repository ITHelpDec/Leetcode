// naive - O(n^2) time, O(1) space
class Solution1 {
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target)
    {
        for (int i = 0; i != nums.size() - 1; ++i)
            for (int j = i + 1; j != nums.size(); ++j)
                if (nums[i] + nums[j] == target) { return { i, j }; }
        return {};
    }
};

// O(n) time, O(n) space
class Solution2 {
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target)
    {
        // we aim to split the elements in "nums" into their corresponding values and positions
        std::unordered_map<int, int> uimap;

        // add value and position as we go along to both save on space and only refer backwards from our current position in nums
        for (int i = 0; i != nums.size(); ++i) {
            if (uimap.count(target - nums[i]))
                return { uimap[target - nums[i]], i };
            uimap[nums[i]] = i;
        }
        
        return {};
    }
};
