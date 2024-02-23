// dfs solution O(V + E)
// if the current grid square is an island, dfs to see how far it goes and increment the counter
// when performing the dfs, check bounds and check to see if we've checked this grid element already

class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        int answer = 0;

        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    ++answer;
                }
            }
        }

        return answer;
    }
private:
    template <typename CV>
    void dfs(CV &visited, int i, int j, int n, int m) {
        if (i != std::clamp(i, 0, n - 1) || j != std::clamp(j, 0, m - 1) || grid[i][j] == '0')
            return;
        
        visited[i][j] = '0';

        dfs(visited, i + 1, j,     n, m);
        dfs(visited, i - 1, j,     n, m);
        dfs(visited, i,     j + 1, n, m);
        dfs(visited, i,     j - 1, n, m);
    }
};
