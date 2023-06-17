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
        std::unordered_multiset umset(nums.begin(),nums.end());

        for (int i = 0; i != nums.size() - 1; ++i)
            if (umset.count(target - nums[i]))
                for (int j = i + 1; j != nums.size(); ++j)
                    if (nums[i] + nums[j] == target) { return { i, j }; }
        return {};
    }
};
