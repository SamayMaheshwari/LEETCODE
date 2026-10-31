class Solution {
    int m, n;
    const int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int help(vector<vector<int>>& grid, int r, int c, int d) {
        if (r == m - 1 && c == n - 1)
            return 1;

        if (r >= m || c >= n)
            return 0;

        if (dp[r][c][d] != -1)
            return dp[r][c][d];

        if (grid[r][c] == 1) {
            if (d == 0)
                return dp[r][c][d] = help(grid, r + 1, c, 1);
            else
                return dp[r][c][d] = help(grid, r, c + 1, 0);
        }

        return dp[r][c][d] = (
            help(grid, r + 1, c, 1) +
            help(grid, r, c + 1, 0)
        ) % mod;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        return help(grid, 0, 0, 0);
    }
};