class Solution {
public:
    int mod = 1e9 + 7;
    int fun(vector<vector<int>>& grid, int k, int i, int j, int m, int n, int xr, vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m) return 0;
        if (i == n - 1 && j == m - 1) {
            if ((xr ^ grid[i][j]) == k) return 1;
            else return 0;
        }
        if (dp[i][j][xr] != -1) return dp[i][j][xr];
        int right = fun(grid, k, i, j + 1, m, n, xr ^ grid[i][j], dp) % mod;
        int down = fun(grid, k, i + 1, j, m, n, xr ^ grid[i][j], dp) % mod;
        return dp[i][j][xr] = (right + down) % mod;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(16, -1)));
        return fun(grid, k, 0, 0, m, n, 0, dp) % mod;
    }
};