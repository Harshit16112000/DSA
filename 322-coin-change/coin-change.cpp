class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        for (int i = 0; i <= amount; i++) {
            dp[0][i] = 1e4 + 1;
            if (i % coins[0] == 0)
                dp[0][i] =  i/coins[0];
        }

        for(int i=1;i<coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nonTake = dp[i-1][j];
                int take = 1e4 + 1;
                if (j >= coins[i])
                    take = 1 + dp[i][j - coins[i]] ;
                dp[i][j] = min(take, nonTake);
            }
        }

        int ans = dp[coins.size()-1][amount];

        if(ans == 1e4  + 1)  return -1;
        return ans;
    }
};