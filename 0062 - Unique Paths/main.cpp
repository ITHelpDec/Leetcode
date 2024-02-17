// O(m * n) solution, but only requires a single int vector intead of nested vectors
// rather than calculate every cell (like with a m * n std::vector<std::vector<int>>()), ...
// ...we are only really interested in the accumulation of each bottom-right corner 

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp(n, 1);

        for (int mi = 1; mi != m; ++mi) {
            for (int ni = 1; ni != n; ++ni) {
                dp[ni] += dp[ni - 1];
            }
        }

        return dp[n - 1];
    }
};
