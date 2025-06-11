class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return  dpProblem(0,amount, coins, dp) == 1e4+1 ? -1 :   dpProblem(0,amount, coins, dp);        
    }

    int dpProblem(int index, int amount, vector<int>& coins, vector<vector<int>>& dp)
    {
        
        if(index == coins.size() -1 )
        {
            if(amount%coins[index] ==0)  return 1;
            else  return 0;
        }

        if(dp[index][amount] != -1)  return dp[index][amount];
        int nonTake = dpProblem(index+1, amount, coins, dp);
        int take = 0;
        if(amount >= coins[index])
           take = dpProblem(index, amount - coins[index], coins, dp);

        return dp[index][amount] = take + nonTake;
    }
};