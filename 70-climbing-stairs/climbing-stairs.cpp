class Solution {
public:
    int dpProblem(int ind, vector<int> &dp)
    {
        if(ind  == 0 || ind == 1)  {
            return 1;
        }
        if(dp[ind] != -1)  return dp[ind];
        int oneStep = dpProblem(ind-1,dp);
        int secondStep = dpProblem(ind-2,dp);

        return dp[ind] = oneStep + secondStep; 
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        if(n ==1 )  return 1;
        dpProblem(n,dp);
        return dp[n];
    }
};