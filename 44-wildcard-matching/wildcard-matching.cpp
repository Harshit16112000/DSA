class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        
        dp[0][0] = true; // empty string matches empty pattern

        // Fill first row (string is empty)
        for (int j = 1; j <= n2; j++) {
            if (p[j - 1] == '*')
            //  I thought this one
              //  dp[0][j] = true
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j]     // '*' matches one or more
                             || dp[i][j - 1];   // '*' matches empty
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n1][n2];
    }
};
