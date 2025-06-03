class Solution {
public:
    int dpProblem(int ind, vector<int> &dp)
    {
        if(ind  == 1 || ind == 2)  {
            dp[ind] = 1;
            return ind;
        }
        if(dp[ind] != -1)  return dp[ind];
        int oneStep = dpProblem(ind-1,dp);
        int secondStep = dpProblem(ind-2,dp);

        return dp[ind] = oneStep + secondStep; 
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
        return dpProblem(n,dp);
    }
};