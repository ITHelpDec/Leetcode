// O(n) solution, O(n) space - eager evaluation approach
class Solution {
public:
    bool containsDuplicate(const std::vector<int> &nums) {
        std::set<int> iset(nums.begin(), nums.end());
        
        return iset.size() != nums.size();
    }
};

// O(n) time, O(n) space, less than above
class Solution2 {
public:
    bool containsDuplicate(const std::vector<int> &nums) {
        std::set<int> iset;

        for (const int num : nums) {
            if (iset.count(num)) { return true; }
            iset.emplace(num);
        }

        return false;
    }
};

// O(nlogn) time, O(1) solution
class Solution3 {
public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        for (std::size_t i = 0; i != nums.size() - 1; ++i)
            if (nums[i] == nums[i + 1]) { return true; }

        return false;
    }
};
