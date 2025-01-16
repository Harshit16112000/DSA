class Solution {
public:
    
    long long solve(int index, vector<vector<int>>& questions, vector<long long>& dp)
    {

        if(index >= questions.size())  return 0;
        if(dp[index] != -1) return dp[index];

        long long take = solve(1 + questions[index][1] + index, questions, dp) + questions[index][0];
        long long  nontake = solve(index+1, questions, dp);

        return dp[index] = max(take, nontake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return solve(0, questions, dp);   
    }
};