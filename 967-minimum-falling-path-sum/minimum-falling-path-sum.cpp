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

        for(int i=0;i<n;i++)
        {
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up = dp[i-1][j];
                int left = j>0 ? dp[i-1][j-1] : INT_MAX;
                int right = j<n-1 ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = min({up, left, right}) + matrix[i][j];
            }
        }

        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
    }
};