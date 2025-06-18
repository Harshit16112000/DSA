class Solution {
public:
    int dpProblem(int ind1, int ind2, string &s, string &t, vector<vector<int>>& dp)
    {
        if(ind2 >= t.size())   return 1;
         if(ind1 >= s.size())   return 0;
        
        if(dp[ind1][ind2] != -1)  return dp[ind1][ind2];

        if(s[ind1] == t[ind2])
        {
            return dp[ind1][ind2] = (dpProblem(ind1+1,ind2+1,s,t,dp) + dpProblem(ind1+1 , ind2, s, t, dp));
        }
        return dp[ind1][ind2] =  dpProblem(ind1+1,ind2,s,t,dp); 
        
    }

    int numDistinct(string s, string t) {
     int n = s.size();
     int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
     
     return dpProblem(0,0,s,t,dp);   
    }
};