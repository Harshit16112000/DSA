class Solution {
public:
    const int prime = 1e9 + 7;
    int numDistinct(string s, string t) {
     int n = s.size();
     int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
     
    // Did the mistake here 
    //  for(int i=0;i<m;i++)
    //  {
    //     if(s[0] == t[i])  dp[0][i] = 1;
    //  }

    // Base Case: An empty t ("") is a subsequence of any prefix of s exactly once
     for(int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
    }

     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1] == t[j-1])
            {
               dp[i][j] =  (dp[i-1][j] + dp[i-1][j-1])% prime;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }   
        }


    }
    return dp[n][m];

    }
};