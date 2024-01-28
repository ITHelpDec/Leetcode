// Expected this one to be harder for a medium
// Could sort first, but that would be logarithmic - unaware of constant time solution

// Traverse from index 1 and conpare current number with previous number - return first number, otherwise
class Solution1 {
public:
    int findMin(std::vector<int> &nums) {
        for (int i = 1; i != nums.size(); ++i)
            if (nums[i] <  nums[i - 1]) { return nums[i]; }
        return nums.front();
    }
};

// Could possibly even just use std::min_element(), and check if .front() is less than .back() (already pre-sorted)
// If we can't expect sorted arrays, then we could get away with not having the check
class Solution2 {
public:
    int findMin(const std::vector<int> &nums) {
        if (nums.front() < nums.back()) { return nums.front(); }
        return *std::min_element(nums.begin(), nums.end());
    }
};

// Solution2 feels more idiomatic, but potentially Solution1 is faster
// Both could be tweaked to provide number of rotations instead of number, if needs be
