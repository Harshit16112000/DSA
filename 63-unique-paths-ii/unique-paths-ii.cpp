class Solution {
public:
     int solve(int m,int n,vector<vector<int>>&obs, vector<vector<int>> &dp)
    {
        
        if(m>=0 && n>=0 && obs[m][n] == 1)
        {
            return 0;
        }

        if(m == 0 && n == 0)
        return 1;
        if(m < 0 || n < 0)
        return 0;

        

        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        int left = solve(m-1,n,obs,dp);
        int right = solve(m,n-1,obs,dp);
        return dp[m][n] = left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)   return 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j ==0)  dp[i][j] = 1;
                else if(obstacleGrid[i][j] == 1)  dp[i][j] = 0;
                else {
                    int up = 0;
                    if(i > 0) up += dp[i-1][j];
                    int right = 0;
                    if(j > 0)  right = dp[i][j-1];
                    dp[i][j] = up + right;
                }
            }
        }

        return dp[m-1][n-1];
        

        
    }
};