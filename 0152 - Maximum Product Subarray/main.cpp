// O(n) solution (two passes), with O(1) space
// Similar kind of Mr Miyagi "wax on, wax off" approach to Product of Array Except Self, combined with Maximum Subarray
// This time we reset our subarray in between "brush strokes"
// I feel like there must be a better way to do this, though...

class Solution {
public:
    int maxProduct(const std::vector<int> &nums) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            current *= *it;
            max      = std::max(current, max);
            if (current == 0) { current = 1; }
        }

        current = 1;

        for (auto rit = nums.rbegin(); rit != nums.rend(); ++rit) {
            current *= *rit;
            max      = std::max(current, max);
            if (current == 0) { current = 1; }
        }

        return max;
    }
private:
    int current = 1;
    int max     = INT_MIN;
};
