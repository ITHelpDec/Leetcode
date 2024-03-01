// O(log(n)) solution, due to the sort (would be O(n) if intervals were already sorted)
// crux of the solution is, go through all of the intervals
// if there's no overlap, add it to our answer vector
// if there is an overlap, increase the ".second" element in our answer to whichever's greater - it, or the interval

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
        std::vector<std::vector<int>> answer;
        
        std::sort(intervals.begin(), intervals.end());

        for (const auto &interval : intervals) {
            if (answer.empty() || interval.front() > answer.back().back()) {
                answer.emplace_back(interval);
            } else {
                answer.back().back() = std::max(answer.back().back(), interval.back());
            }
        }

        return answer;
    }
};
