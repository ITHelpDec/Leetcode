// O(nlog(n)) solution due to the sort
// we sort the interals by their "end" elements, and compare the current interval to the previous elemnet
// if the interval-we're-on's "start" element is greater-than-or-equal-to the "end" of the last interval we checked, ...
// ... then we increase our non-merging count and shift the "previous" position up one
// return the total number of intervals, minus the number of intervals that are non-merging

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
        int n = intervals.size();

        std::sort(intervals.begin(), intervals.end(), [] (const auto &lhs, const auto &rhs) {
            return lhs.back() < rhs.back();
        });

        int prev  = 0;
        int count = 1;

        for (int i = 1; i != n; ++i) {
            if (intervals[i].front() >= intervals[prev].back()) {
                prev = i;
                ++count;
            }
        }

        return n - count;
    }
};
