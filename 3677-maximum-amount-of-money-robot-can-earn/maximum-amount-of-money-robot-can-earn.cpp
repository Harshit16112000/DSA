class Solution {
public:
    long long solve(int i, int j, vector<vector<int>>& coins,
              vector<vector<vector<int>>>& dp, int k,
              vector<vector<vector<int>>>& visited) {

        if (i >= coins.size() || j >= coins[0].size())
            return INT_MIN;

        if (i == coins.size() - 1 && j == coins[0].size() - 1) {
            if (coins[i][j] < 0 && k > 0)
                return 0;
            return coins[i][j];
        }
        if (visited[i][j][k])
            return dp[i][j][k];

        long long right = INT_MIN, down = INT_MIN;

        right = coins[i][j] + solve(i, j + 1, coins, dp, k, visited);
        if (k > 0 && coins[i][j] < 0) 
        {
            right = max(right, solve(i, j + 1,coins, dp, k - 1, visited));
        }

        down = solve(i + 1, j, coins, dp, k, visited) + coins[i][j];
        if (k > 0 && coins[i][j] < 0)
            down = max(down, solve(i + 1, j,coins, dp, k - 1, visited));

        visited[i][j][k] = 1;
        return dp[i][j][k] = max(right, down);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1)));
        vector<vector<vector<int>>> visited(
            m, vector<vector<int>>(n, vector<int>(3, 0)));

        return solve(0, 0, coins, dp, 2, visited);
    }
};