// separate the known from the unknown
// if we can't achieve the target mean, return a blank vector
// return a vector of n items that cover the missing difference
// distribute the remainder accordingly (across one or multiple items)

class Solution {
public:
    std::vector<int> missingRolls(const std::vector<int> &rolls, int mean, int n) {
        int known_sum = std::accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();

        int missing_sum = mean * (n + m) - known_sum;

        if (missing_sum < n || missing_sum > (6 * n)) { return {}; }
        
        int part = missing_sum / n;
        int rem  = missing_sum % n;

        std::vector<int> answer(n, part);
        
        for (int i = 0; i != rem; ++i) { ++answer[i]; }

        return answer;
    }
};
