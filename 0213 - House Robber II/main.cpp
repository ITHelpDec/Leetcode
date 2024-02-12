// dp solution, similar to house robber 1
// same technique, just change ranges - 0 to one-off to first pass, 1 to end for second (this can no doubt be combined for a single pass
// return the largest of the two maxes
class Solution {
public:
    int rob(const std::vector<int> &nums) {
        if (nums.size() < 4) { return *std::max_element(nums.begin(), nums.end()); }

        int even_previous = 0;
        int even_current  = 0;

        for (int i = 0; i != nums.size() - 1; ++i) {
            int even_next = std::max(even_current, even_previous + nums[i]);
            even_previous = even_current;
            even_current  = even_next;
        }

        int odd_previous = 0;
        int odd_current  = 0;

        for (int i = 1; i != nums.size(); ++i) {
            int odd_next = std::max(odd_current, odd_previous + nums[i]);
            odd_previous = odd_current;
            odd_current  = odd_next;
        }

        return std::max(even_current, odd_current);
    }
};
