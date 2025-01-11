class Solution {
public:
    int solve(int ind1, int ind2,string& str1, string& str2, vector<vector<int>> &dp)
    {
        if(ind1 < 0 || ind2 < 0)
        return 0;

        if(dp[ind1][ind2] != -1)
          return dp[ind1][ind2];
        int ans = 0;
        if(str1[ind1] == str2[ind2])
            ans = (1 + solve(ind1-1,ind2-1,str1,str2,dp));
        
         ans = max({
            solve(ind1-1,ind2,str1,str2,dp),solve(ind1,ind2-1,str1,str2,dp), ans});
         return dp[ind1][ind2] = ans;
    }

    int longestPalindromeSubseq(string s) {
        int ind1 = s.size();
        string r = s;
        reverse(r.begin(),r.end());

        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        int ans = solve(ind1-1,ind1-1,s,r,dp);
        return ans;
    }
};