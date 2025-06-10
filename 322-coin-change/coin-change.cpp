class Solution {
public:
    int dpProblem(int index, int amount, vector<int>& coins, vector<vector<int>>& dp)
    {
        
        if(index == coins.size() -1 )
        {
            if(amount%coins[index] ==0)  return amount/coins[index];
            else  return 1e4 + 1;
        }

        if(dp[index][amount] != -1)  return dp[index][amount];
        int nonTake = dpProblem(index+1, amount, coins, dp);
        int take = 1e4 + 1;
        if(amount >= coins[index])
           take = 1 + dpProblem(index, amount - coins[index], coins, dp);

        return dp[index][amount] = min(take, nonTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));

        
        return  dpProblem(0,amount, coins, dp) == 1e4+1 ? -1 :   dpProblem(0,amount, coins, dp);
    }
};