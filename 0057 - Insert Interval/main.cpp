// O(n) solution, of O(n) space
// we're basically reconstructing the intervals from beginning to end
// (1) go as far as the "start" of newInterval is less than the "end" of our current interval
// (2) work out how far we need to merge intervals
// (3) add the rest of the intervals

class Solution {
public:
    template <typename IVV, typename IV>
    IVV insert(IVV &intervals, IV &newInterval) {
        int i = 0;
        int n = intervals.size();

        IVV answer;

        while (i < n && intervals[i].back() < newInterval.front()) {
            answer.emplace_back(intervals[i]);
            ++i;
        }

        while (i < n && newInterval.back() >= intervals[i].front()) {
            newInterval.front() = std::min(newInterval.front(), intervals[i].front());
            newInterval.back()  = std::max(newInterval.back(),  intervals[i].back());
            ++i;
        }

        answer.emplace_back(newInterval);

        while (i < n) {
            answer.emplace_back(intervals[i]);
            ++i;
        }

        return answer;
    }
};
