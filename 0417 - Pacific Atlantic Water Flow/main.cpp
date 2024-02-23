// dfs solution
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        std::vector<std::vector<bool>>  pacific(n, std::vector<bool>(m, false));
        std::vector<std::vector<bool>> atlantic(n, std::vector<bool>(m, false));

        for (int i = 0; i != n; ++i) {
            dfs(pacific,  heights, i, 0,     INT_MIN, n, m);
            dfs(atlantic, heights, i, m - 1, INT_MIN, n, m);            
        }

        for (int j = 0; j != m; ++j) {
            dfs(pacific,  heights, 0,     j, INT_MIN, n, m);
            dfs(atlantic, heights, n - 1, j, INT_MIN, n, m);
        }

        std::vector<std::vector<int>> answer;

        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (atlantic[i][j] && pacific[i][j]) {
                    answer.push_back({ i, j });
                }
            }
        }

        return answer;
    }
private:
    template <typename BV, typename IV>
    void dfs(BV visited, IV heights, int i, int j, int previous_height, int n, int m) {
        if (i != std::clamp(i, 0, n - 1) || j != std::clamp(j, 0, m - 1) || visited[i][j] == true || heights[i][j] < previous_height) {
            return;
        }

        visited[i][j] = true;

        dfs(visited, heights, i + 1, j,     heights[i][j], n, m);
        dfs(visited, heights, i - 1, j,     heights[i][j], n, m);
        dfs(visited, heights, i,     j + 1, heights[i][j], n, m);
        dfs(visited, heights, i,     j - 1, heights[i][j], n, m);
    }
};
