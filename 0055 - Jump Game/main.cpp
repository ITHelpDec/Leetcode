// O(n) dp solution

class Solution {
public:
    bool canJump(const std::vector<int> &nums) {
        int max = nums[0];

        for (int i = 0; i != nums.size(); ++i) {
            if (i > max) { return false; }
            max = std::max(max, nums[i] + i);
        }

        return true;
    }
};
