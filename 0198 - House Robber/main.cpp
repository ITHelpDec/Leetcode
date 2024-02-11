// bottom-up dp solution similar to "c = a + b; a = b; b = c" fibonacci solution
// only differece is "c" is the max of either the current max or the last max plus the current element
class Solution {
public:
    int rob(const vector<int> &nums) {
        int previous = 0;
        int current  = 0;

        for (int i = 0; i != nums.size(); ++i) {
            int next = std::max(current, previous + nums[i]);
            previous = current;
            current  = next;
        }

        return current;
    }
};
