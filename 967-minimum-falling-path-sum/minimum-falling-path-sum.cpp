class Solution {
public:
    int dpProblem(int row, int col, vector<vector<int>>& matrix,
                  vector<vector<int>>& dp) {
        if (col < 0 || col > matrix.size()-1)
            return INT_MAX;
            
        if (row == matrix.size() - 1)
            return matrix[row][col];

        if (dp[row][col] != -101)
            return dp[row][col];

        
        int down = dpProblem(row + 1, col, matrix, dp);
        int left = dpProblem(row + 1, col - 1, matrix, dp);
        int right = dpProblem(row + 1, col + 1, matrix, dp);

        return dp[row][col] = min(left, min(right, down)) + matrix[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -101));

        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, dpProblem(0, i, matrix, dp));
        }
        return mini;
    }
};