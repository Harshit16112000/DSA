class Solution {
public:

   int solve(int ind1, int ind2,string& str1, string& str2, vector<vector<int>> &dp)
    {
        if(ind1 < 0 || ind2 < 0)
        return 0;

        if(dp[ind1][ind2] != -1)
          return dp[ind1][ind2];

        if(str1[ind1] == str2[ind2])
         return dp[ind1][ind2] =  1 + solve(ind1-1,ind2-1,str1,str2,dp);
        
        return dp[ind1][ind2] = max(solve(ind1-1,ind2,str1,str2,dp) , solve(ind1,ind2-1,str1,str2,dp));
    }

    
    int minInsertions(string s) {
                int n = s.size();
                string p = s;
                 reverse(s.begin(),s.end());
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ansc = n - solve(n-1,m-1,s,p,dp);
        return ansc;       
    
    }

};