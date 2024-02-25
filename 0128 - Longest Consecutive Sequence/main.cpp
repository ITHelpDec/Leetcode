// asked for O(n) solution
// insertions and reads from unordered sets are of constant time - iterating thrugh our vector of numbers is O(n)
// other solutions suggested std::sort(), but this is O(nlogn), with std::stable_sort() being O(log(n^2)) on overage

// crux of the problem is to go through the list of numbers
// if we can't find the previous number of the sequence in our set, start a counter
// keep counting each consecutive number found in the set until we hit a dead end
// at each dead end, see if your counter is larger than the largest count so far

class Solution {
public:
    int longestConsecutive(const std::vector<int> &nums) {
        std::unordered_set<int> uiset(nums.begin(), nums.end());

        int longest = 0;

        for (const int num : nums) {
            if (uiset.find(num - 1) == uiset.end()) {
                int current = num;

                int counter = 1;
                while (uiset.find(current + 1) != uiset.end()) {
                    ++current;
                    ++counter;
                }

                longest = std::max(longest, counter);
            }
        }

        return longest;
    }
};
