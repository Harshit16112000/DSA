class Solution {
public:
    #define ll long long
    int peopleAwareOfSecret(int n, int delay, int forget) {
     vector<int> dp(n+1, 0);
     dp[0] = 1;
    int mod = 1000000007;
     for(int i=0;i<n;i++)
     {
        if(dp[i] == 0)  continue;

        for(int j = i + delay; j < n && (j-i) < forget; j++)
        {
            dp[j] += dp[i];
            dp[j] = dp[j]%mod;
        }
     } 

     for(int i=0;i<dp.size();i++)
     {
        cout << dp[i] << " ";
     }  
    
    int cnt = 0;
     for(int i=n-1;i>= n-forget;i--)
     {
        cnt += dp[i];
        cnt = cnt%mod;
     }

     return cnt;
    }
};