// O(n) solution / O(1) space
// set up dp array, and keep a track of the tens and units
// increment our current dp element if the current number is a valid single-/double-digit number

class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> dp(s.size() + 1, 0);

        dp[0] = 1;
        dp[1] = (s[0] != '0');

        for (int i = 2; i != s.size() + 1; ++i) {
            char t = s[i - 2]; // tens
            char u = s[i - 1]; // units

            if (u != '0') { dp[i] += dp[i - 1]; }

            if (t == '1' || (t == '2' && u == std::clamp(u, '0', '6'))) {
                dp[i] += dp[i - 2];
            }
        }

        return dp.back();
    }
};
