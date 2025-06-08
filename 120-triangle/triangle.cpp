class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {
        if (row == triangle.size() - 1)
            return triangle[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];
        int row1 = triangle[row][col] + solve(row + 1, col, triangle, dp);
        int row2 = triangle[row][col] + solve(row + 1, col + 1, triangle, dp);
        return dp[row][col] = min(row1, row2);
        // return dp[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j < triangle[i - 1].size())
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);

                if (j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            }
        }

        int mini = INT_MAX;
        for (int i = 0; i < triangle.size(); i++) {
            mini = min(mini, dp[n - 1][i]);
        }

        return mini;
        // return solve(0,0,triangle,dp);
    }
};