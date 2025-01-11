class Solution {
public:
    int solve(int index, int k,vector<vector<int>>& piles, vector<vector<int>> &dp)
    {
        if(index == piles.size() || k == 0)  return 0;
        if(dp[index][k] != -1)  return dp[index][k];

        int skipPiles = solve(index+1,k,piles,dp);
        int takePiles = 0;
        int cur = 0;
        for(int j=0;j < piles[index].size() && j <k ; j++)
        {
            cur += piles[index][j];
            takePiles = max(takePiles,solve(index+1,k-j-1,piles,dp) + cur); 
        }

        return dp[index][k] = max(takePiles, skipPiles);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n =piles.size();

        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));

        return solve(0,k,piles,dp);
    }
};