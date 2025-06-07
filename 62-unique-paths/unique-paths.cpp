class Solution {
public:
    int dpProblem(int row, int col, vector<vector<int>> &dp, int m, int n)
    {
        if(row >= m || col >= n) return 0;
        if(row == m-1 && col == n-1)  return 1;
        

        if(dp[row][col] != -1)  return dp[row][col];
        int right = dpProblem(row+1,col,dp,m,n);
        int down = dpProblem(row, col+1, dp,m,n);

        return dp[row][col] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));

        return dpProblem(0,0,dp,m,n);

    }
};